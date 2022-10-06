/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/27 17:19:11 by mforstho      #+#    #+#                 */
/*   Updated: 2022/10/06 16:35:32 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_array(char **arr)
{
	int	y;

	if (arr == NULL)
		return ;
	y = 0;
	while (arr[y] != NULL)
	{
		free(arr[y]);
		y++;
	}
	free(arr);
}

void	free_em(t_free_this *free_these)
{
	free(free_these->command_path);
	free_array(free_these->command);
	free_array(free_these->path_array);
}

void	exit_error(char *prefix, t_free_this *free_these)
{
	perror(prefix);
	if (free_these != NULL)
		free_em(free_these);
	exit(EXIT_FAILURE);
}

static void	initialize_data(t_data *data, int argc, char *argv[], char *envp[])
{
	data->argc = argc;
	data->infile = argv[1];
	data->cmd1 = argv[2];
	data->cmd2 = argv[3];
	data->outfile = argv[4];
	data->envp = envp;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data		data;
	t_free_this	free_these;
	int			pipe_fds[2];

	ft_bzero(&free_these, sizeof(free_these));
	initialize_data(&data, argc, argv, envp);
	if (argc != 5)
	{
		ft_putendl_fd("pipex: incorrect number of arguments", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	if (pipe(pipe_fds) == -1)
		exit_error("pipex: pipe", &free_these);
	exec_left(pipe_fds, &data, &free_these);
	close(pipe_fds[WRITE]);
	exec_right(pipe_fds, &data, &free_these);
	close(pipe_fds[READ]);
	free_em(&free_these);
	wait(NULL);
	wait(NULL);
	return (EXIT_SUCCESS);
}

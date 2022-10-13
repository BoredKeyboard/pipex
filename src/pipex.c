/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/27 17:19:11 by mforstho      #+#    #+#                 */
/*   Updated: 2022/10/13 12:31:24 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_em(t_free_this *free_these)
{
	free(free_these->command_path);
	free_array(free_these->command);
	free_array(free_these->path_array);
}

void	exit_error(char *prefix, t_free_this *free_these, int exit_status)
{
	perror(prefix);
	if (free_these != NULL)
		free_em(free_these);
	exit(exit_status);
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

int	wait_for_children(pid_t pid_right)
{
	int	stat_loc;
	int	return_value;

	return_value = EXIT_SUCCESS;
	if (wait(&stat_loc) == pid_right)
		return_value = WEXITSTATUS(stat_loc);
	if (wait(&stat_loc) == pid_right)
		return_value = WEXITSTATUS(stat_loc);
	return (return_value);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data		data;
	t_free_this	free_these;
	int			pipe_fds[2];
	pid_t		pid_right;

	ft_bzero(&free_these, sizeof(free_these));
	initialize_data(&data, argc, argv, envp);
	if (argc != 5)
	{
		ft_putendl_fd("pipex: incorrect number of arguments", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	if (pipe(pipe_fds) == -1)
		exit_error("pipex: pipe", &free_these, EXIT_FAILURE);
	exec_left(pipe_fds, &data, &free_these);
	close(pipe_fds[WRITE]);
	pid_right = exec_right(pipe_fds, &data, &free_these);
	close(pipe_fds[READ]);
	free_em(&free_these);
	return (wait_for_children(pid_right));
}

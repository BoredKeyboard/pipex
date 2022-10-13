/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   px_exec.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 18:14:27 by mforstho      #+#    #+#                 */
/*   Updated: 2022/10/13 12:32:01 by mforstho      ########   odam.nl         */
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

void	exec_command(t_data *data, t_free_this *free_these, char *cmd)
{
	free_these->command = ft_split(cmd, ' ');
	if (free_these->command == NULL)
		exit_error("pipex", free_these, EXIT_FAILURE);
	free_these->command_path = NULL;
	if (free_these->command[0] != NULL)
	{
		free_these->command_path = resolve_command_path(free_these->command[0],
				data, free_these);
		if (free_these->command_path == NULL)
			exit_error("pipex", free_these, EXIT_FAILURE);
	}
	if (dup2(data->input, STDIN_FILENO) == -1)
		exit_error("pipex: dup2", free_these, EXIT_FAILURE);
	if (dup2(data->output, STDOUT_FILENO) == -1)
		exit_error("pipex: dup2", free_these, EXIT_FAILURE);
	if (free_these->command_path != NULL)
	{
		if (execve(free_these->command_path,
				free_these->command, data->envp) == -1)
			exit_error("pipex: execve", free_these, EXIT_FAILURE);
	}
	free_em(free_these);
	exit(EXIT_SUCCESS);
}

pid_t	exec_left(int pipe_fds[2], t_data *data, t_free_this *free_these)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_error("pipex: fork", free_these, EXIT_FAILURE);
	if (pid == 0)
	{
		close(pipe_fds[READ]);
		data->output = pipe_fds[WRITE];
		data->input = open(data->infile, O_RDONLY);
		if (data->input == -1)
		{
			ft_putstr_fd("pipex: ", STDERR_FILENO);
			exit_error(data->infile, free_these, EXIT_FAILURE);
		}
		exec_command(data, free_these, data->cmd1);
	}
	return (pid);
}

pid_t	exec_right(int pipe_fds[2], t_data *data, t_free_this *free_these)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_error("pipex: fork", free_these, EXIT_FAILURE);
	if (pid == 0)
	{
		data->output = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (data->output == -1)
		{
			ft_putstr_fd("pipex: ", STDERR_FILENO);
			exit_error(data->outfile, free_these, EXIT_FAILURE);
		}
		data->input = pipe_fds[READ];
		exec_command(data, free_these, data->cmd2);
	}
	return (pid);
}

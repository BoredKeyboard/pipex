/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   px_exec.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 18:14:27 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/29 18:19:20 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_command(int infile, int outfile, char *cmd, char *envp[])
{
	char	*file_path;
	char	**command;

	command = ft_split(cmd, ' ');
	if (command == NULL)
		exit_error("pipex");
	file_path = resolve_command_path(command[0], envp);
	if (dup2(infile, STDIN_FILENO) == -1)
		exit_error("pipex: dup2");
	if (dup2(outfile, STDOUT_FILENO) == -1)
		exit_error("pipex: dup2");
	if (file_path != NULL)
	{
		if (execve(file_path, command, envp) == -1)
			exit_error("pipex: execve");
	}
	exit(EXIT_SUCCESS);
}

pid_t	exec_left(int pipe_fds[2], char *infile, char *cmd, char *envp[])
{
	int		opened_fd;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_error("pipex: fork");
	if (pid == 0)
	{
		close(pipe_fds[READ]);
		opened_fd = open(infile, O_RDONLY);
		if (opened_fd == -1)
		{
			ft_putstr_fd("pipex: ", STDERR_FILENO);
			exit_error(infile);
		}
		exec_command(opened_fd, pipe_fds[WRITE], cmd, envp);
	}
	return (pid);
}

pid_t	exec_right(int pipe_fds[2], char *outfile, char *cmd, char *envp[])
{
	int		opened_fd;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_error("pipex: fork");
	if (pid == 0)
	{
		opened_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (opened_fd == -1)
		{
			ft_putstr_fd("pipex: ", STDERR_FILENO);
			exit_error(outfile);
		}
		exec_command(pipe_fds[READ], opened_fd, cmd, envp);
	}
	return (pid);
}

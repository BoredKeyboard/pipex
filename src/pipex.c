/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/27 17:19:11 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/29 18:14:47 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	leakfunction(void)
{
	ft_putendl_fd("", STDOUT_FILENO);
	system("leaks -q pipex");
}

void	exit_error(char *prefix)
{
	perror(prefix);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		pipe_fds[2];

	atexit(leakfunction);
	if (argc != 5)
	{
		ft_putendl_fd("pipex: incorrect number of arguments", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	if (pipe(pipe_fds) == -1)
		exit_error("pipex: pipe");
	exec_left(pipe_fds, argv[1], argv[2], envp);
	close(pipe_fds[WRITE]);
	exec_right(pipe_fds, argv[4], argv[3], envp);
	close(pipe_fds[READ]);
	wait(NULL);
	wait(NULL);
	return (EXIT_SUCCESS);
}

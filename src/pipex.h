/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 16:09:20 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/29 18:18:33 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define READ 0
# define WRITE 1

# include "libft.h"

void	exit_error(char *prefix);

char	*append_command(char *path, char *command);
char	*search_path(char **path_arr, char *command);
char	*get_envp_var(char *envp[], char *var_name);
char	**get_path_array(char *envp[]);
char	*resolve_command_path(char *cmd, char *envp[]);

void	exec_command(int infile, int outfile, char *cmd, char *envp[]);
pid_t	exec_left(int pipe_fds[2], char *infile, char *cmd, char *envp[]);
pid_t	exec_right(int pipe_fds[2], char *outfile, char *cmd, char *envp[]);

#endif
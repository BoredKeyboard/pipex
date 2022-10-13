/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 16:09:20 by mforstho      #+#    #+#                 */
/*   Updated: 2022/10/13 12:31:09 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

# define READ 0
# define WRITE 1

# include "libft.h"

typedef struct s_data {
	int		argc;
	char	*infile;
	char	*cmd1;
	char	*cmd2;
	char	*outfile;
	char	**envp;
	int		input;
	int		output;
}	t_data;

typedef struct s_free_this {
	char	*command_path;
	char	**command;
	char	**path_array;
}	t_free_this;

void	free_em(t_free_this *free_these);
void	exit_error(char *prefix, t_free_this *free_these, int exit_status);

char	*append_command(char *path, char *command, t_free_this *free_these);
char	*search_path(char **path_arr, char *command, t_free_this *free_these);
char	*get_envp_var(char *envp[], char *var_name);
char	**get_path_array(char *envp[]);
char	*resolve_command_path(char *cmd, t_data *data, t_free_this *free_these);

void	free_array(char **arr);
void	exec_command(t_data *data, t_free_this *free_these, char *cmd);
pid_t	exec_left(int pipe_fds[2], t_data *data, t_free_this *free_these);
pid_t	exec_right(int pipe_fds[2], t_data *data, t_free_this *free_these);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   px_path.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 18:13:20 by mforstho      #+#    #+#                 */
/*   Updated: 2022/10/12 11:54:53 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>

char	*append_command(char *path, char *command, t_free_this *free_these)
{
	size_t	size;
	char	*cmd_path;

	size = ft_strlen(path) + ft_strlen(command) + 2;
	cmd_path = malloc(size);
	if (cmd_path == NULL)
		exit_error("pipex", free_these);
	ft_strlcpy(cmd_path, path, size);
	ft_strlcat(cmd_path, "/", size);
	ft_strlcat(cmd_path, command, size);
	return (cmd_path);
}

char	*search_path(char **path_arr, char *command, t_free_this *free_these)
{
	int		i;
	char	*file_path;
	bool	seen;

	seen = false;
	i = 0;
	while (path_arr[i] != NULL)
	{
		file_path = append_command(path_arr[i], command, free_these);
		if (access(file_path, F_OK) == 0)
		{
			seen = true;
			if (access(file_path, X_OK) == 0)
				return (file_path);
		}
		free(file_path);
		i++;
	}
	if (seen)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		errno = EPERM;
		exit_error(command, free_these);
	}
	return (NULL);
}

char	*get_envp_var(char *envp[], char *var_name)
{
	int		i;
	int		len;

	len = ft_strlen(var_name);
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], var_name, len) == 0 && envp[i][len] == '=')
		{
			return (envp[i] + len + 1);
		}
		i++;
	}
	return (NULL);
}

char	**get_path_array(char *envp[])
{
	char	*path;

	path = get_envp_var(envp, "PATH");
	if (path == NULL)
		return (NULL);
	return (ft_split(path, ':'));
}

char	*resolve_command_path(char *cmd, t_data *data, t_free_this *free_these)
{
	char	*file_path;

	if (ft_strchr(cmd, '/') != NULL)
	{
		if (access(cmd, X_OK) == -1)
		{
			ft_putstr_fd("pipex: ", STDERR_FILENO);
			exit_error(cmd, free_these);
		}
		return (ft_strdup(cmd));
	}
	free_these->path_array = get_path_array(data->envp);
	file_path = NULL;
	if (free_these->path_array != NULL)
		file_path = search_path(free_these->path_array, cmd, free_these);
	if (file_path == NULL)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);
		free_em(free_these);
		exit(EXIT_FAILURE);
	}
	return (file_path);
}

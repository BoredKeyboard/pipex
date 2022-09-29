/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   px_path.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 18:13:20 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/29 18:19:17 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*append_command(char *path, char *command)
{
	size_t	len;
	char	*cmd_path;

	len = ft_strlen(path) + ft_strlen(command) + 2;
	cmd_path = malloc(len);
	cmd_path[0] = '\0';
	ft_strlcat(cmd_path, path, len);
	ft_strlcat(cmd_path, "/", len);
	ft_strlcat(cmd_path, command, len);
	return (cmd_path);
}

char	*search_path(char **path_arr, char *command)
{
	int		i;
	char	*file_path;

	if (path_arr == NULL)
		return (NULL);
	i = 0;
	while (path_arr[i] != NULL)
	{
		file_path = append_command(path_arr[i], command);
		if (access(file_path, X_OK) == 0)
			return (file_path);
		free(file_path);
		i++;
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

char	*resolve_command_path(char *cmd, char *envp[])
{
	char	*file_path;

	if (cmd == NULL)
		return (NULL);
	if (ft_strchr(cmd, '/') != NULL)
	{
		if (access(cmd, X_OK) == -1)
		{
			ft_putstr_fd("pipex: ", STDERR_FILENO);
			exit_error(cmd);
		}
		return (cmd);
	}
	file_path = search_path(get_path_array(envp), cmd);
	if (file_path == NULL)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (file_path);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/27 17:19:11 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/28 17:02:53 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	leakfunction(void)
{
	system("leaks -q pipex");
}

int	main(int argc, char *argv[])
{
	int	i;
	atexit(leakfunction);

	i = 1;
	if (argc != 5)
	{
		ft_putendl_fd("Insufficient arguments", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	else
	{
		while (argv[i] != NULL)
		{
			ft_putendl_fd(argv[i], STDOUT_FILENO);
			i++;
		}
		ft_putendl_fd("Success", STDOUT_FILENO);
	}
	return (EXIT_SUCCESS);
}

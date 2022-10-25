/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:21:53 by bchabot           #+#    #+#             */
/*   Updated: 2022/10/25 12:59:47 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	pipex(char **av, char **envp)
{
	t_data	data;
	int		pid;
	int		pid2;
	int		fd_pipe[2];

	parse_data(&data, av, envp);
	if (pipe(fd_pipe) == -1)
		return (errno);
	pid = fork();
	if (pid == -1)
		return (errno);
	if (pid == 0)
		first_cmd(&data, fd_pipe, envp);
	else
	{
		pid2 = fork();
		if (pid2 == -1)
			return (errno);
		if (pid2 == 0)
			second_cmd(&data, fd_pipe, envp);
	}
	ft_close(fd_pipe[0], fd_pipe[1]);
	free_struct(&data);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	if (ac == 5)
		pipex(av, envp);
	else
	{
		ft_putstr_fd("Wrong arguments number.\n", 2);
		return (1);
	}
	return (0);
}

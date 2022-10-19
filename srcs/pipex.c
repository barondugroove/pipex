/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:21:53 by bchabot           #+#    #+#             */
/*   Updated: 2022/10/19 18:33:00 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	pipex(char **av, char **envp)
{
	t_data	data;
	int		pid;
	int		fd_pipe[2];

	parse_data(&data, av, envp);
	if (pipe(fd_pipe) == -1)
		return ;
	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
		execute_command1(&data, fd_pipe, envp);
	waitpid(pid, NULL, -1);
	execute_command2(&data, fd_pipe, envp);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	free_struct(&data);
}

int	main(int ac, char **av, char **envp)
{
	if (ac == 5)
		pipex(av, envp);
	else
		ft_putstr_fd("Wrong arguments number.\n", 2);
	return (0);
}

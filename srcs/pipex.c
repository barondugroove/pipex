/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:21:53 by bchabot           #+#    #+#             */
/*   Updated: 2022/10/17 19:47:21 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_data(t_data *data)
{
	int	i;

	i = 0;
	ft_printf("%s\n", data->files[0]);
	ft_printf("%s\n", data->cmd[0]);
	while (data->cmd2[i])
		ft_printf("%s\n", data->cmd2[i++]);
	ft_printf("%s\n", data->files[1]);
	i = 0;
	while (data->path[i])
		ft_printf("%s\n", data->path[i++]);
	write(1, "\n", 1);
	return ;
}

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
	if (pid == 0 && !check_errors(&data))
		execute_command1(&data, fd_pipe, envp);
	waitpid(pid, NULL, 0);
	execute_command2(&data, fd_pipe, envp);
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

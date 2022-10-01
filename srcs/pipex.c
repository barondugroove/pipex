/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:28:54 by bchabot           #+#    #+#             */
/*   Updated: 2022/10/01 16:55:34 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;
	int		fd_pipe[2];
	int		i;

	if (ac == 5)
		parse_data(&data, av, env);
	else
	{
		write(2, "Arguments Error\n", 16);
		return (1);
	}
	if (pipe(fd_pipe) == -1)
		return (1);
	execute_command1(&data, fd_pipe);
	waitpid(-1, NULL, 0);
	execute_command2(&data, fd_pipe);
	free(data.path);
	free(data.files[0]);
	free(data.files[1]);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	i = 0;
	while (data.cmd[i])
		free(data.cmd[i++]);
	free(data.cmd);
	i = 0;
	while (data.cmd2[i])
		free(data.cmd2[i++]);
	free(data.cmd2);
	return (0);
}

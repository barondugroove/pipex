/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:28:54 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/28 21:11:23 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;
	int		fd_pipe[2];
	int		fd_file[2];

	if (ac == 5)
		parse_data(&data, av, env);
	else
	{
		write(2, "Arguments Error\n", 16);
		return (0);
	}
	if (pipe(fd_pipe) == -1)
		return (1);
	execute_command1(&data, fd_pipe, fd_file);
	/*pid[0] = fork();
	if (pid[0] == -1)
	{
		write(2, "ERROR\n", 6);
		return (1);
	}
	if (pid[0] == 0)
	{
		fd_file[0] = open(data.files[0], O_RDONLY);
		dup2(fd_file[0], STDIN_FILENO);
		dup2(fd_pipe[1], STDOUT_FILENO);
		if ((execve(strjoin_pipex(data.path, data.cmd[0]), data.cmd, env)) == -1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		close(fd_file[0]);
	}*/
	waitpid(-1, NULL, 0);
	execute_command2(&data, fd_pipe, fd_file);
	/*pid[1] = fork();
	if (pid[1] == -1)
	{
		write(2, "ERROR\n", 6);
		return (1);
	}
	if (pid[1] == 0)
	{
		waitpid(-1, NULL, 0);
		fd_file[1] = open(data.files[1], O_WRONLY | O_TRUNC | O_CREAT, 0600);
		dup2(fd_pipe[0], STDIN_FILENO);
		dup2(fd_file[1], STDOUT_FILENO);
		if ((execve(strjoin_pipex(data.path, data.cmd2[0]), data.cmd2, env)) == -1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		close(fd_file[1]);
	}*/
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	return (0);
}

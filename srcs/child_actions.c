/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:48:55 by bchabot           #+#    #+#             */
/*   Updated: 2022/10/01 16:49:00 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_command1(t_data *data, int fd_pipe[2])
{
	int	pid;
	int	fd;

	pid = fork();
	if (pid == -1)
	{
		write(2, "ERROR\n", 6);
		return (1);
	}
	if (pid == 0)
	{
		fd = open(data->files[0], O_RDONLY);
		if (fd < 0)
			return (1);
		dup2(fd, STDIN_FILENO);
		dup2(fd_pipe[1], STDOUT_FILENO);
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		close(fd);
		if ((execve(strjoin_pipex(data->path, data->cmd[0]), data->cmd,
					data->env)) == -1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
	return (0);
}

int	execute_command2(t_data *data, int fd_pipe[2])
{
	int	pid;
	int	fd;

	pid = fork();
	if (pid == -1)
	{
		write(2, "ERROR\n", 6);
		return (1);
	}
	if (pid == 0)
	{
		fd = open(data->files[1], O_WRONLY | O_TRUNC | O_CREAT, 0600);
		if (fd < 0)
			return (1);
		dup2(fd_pipe[0], STDIN_FILENO);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		if ((execve(strjoin_pipex(data->path, data->cmd2[0]), data->cmd2,
					data->env)) == -1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
	return (0);
}

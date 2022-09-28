/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_actions->c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student->42->fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:30:57 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/28 20:34:08 by bchabot          ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_command1(t_data *data, int fd_pipe[2], int fd_file[2])
{
	int pid;

	pid = fork();
	if (pid == -1)
	{
		write(2, "ERROR\n", 6);
		return (1);
	}
	if (pid == 0)
	{
		fd_file[0] = open(data->files[0], O_RDONLY);
		dup2(fd_file[0], STDIN_FILENO);
		dup2(fd_pipe[1], STDOUT_FILENO);
		if ((execve(strjoin_pipex(data->path, data->cmd[0]), data->cmd, data->env)) == -1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		close(fd_file[0]);
	}
	return (0);
}

int	execute_command2(t_data *data, int fd_pipe[2], int fd_file[2])
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		write(2, "ERROR\n", 6);
		return (1);
	}
	if (pid == 0)
	{
		waitpid(-1, NULL, 0);
		fd_file[1] = open(data->files[1], O_WRONLY | O_TRUNC | O_CREAT, 0600);
		dup2(fd_pipe[0], STDIN_FILENO);
		dup2(fd_file[1], STDOUT_FILENO);
		if ((execve(strjoin_pipex(data->path, data->cmd2[0]), data->cmd2, data->env)) == -1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		close(fd_file[1]);
	}
	return (0);
}

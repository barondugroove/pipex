/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:48:55 by bchabot           #+#    #+#             */
/*   Updated: 2022/10/10 17:56:39 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	execute_command1(t_data *data, int fd_pipe[2], char **env)
{
	int	pid;
	int	fd;
	char *str;
	int i;

	i = 0;
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		fd = open(data->files[0], O_RDONLY);
		if (fd < 0)
			return (1);
		dup2(fd, STDIN_FILENO);
		dup2(fd_pipe[0], STDOUT_FILENO);
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		close(fd);
		while (data->path[i])
		{
			str = strjoin_pipex(data->path[i++], data->cmd[0]);
			if (!access(str, X_OK))
			{
				if ((execve(str, data->cmd, env)) == -1)
				{
					free(str);
					return (1);
				}
			}
			free(str);
		}
	}
	return (0);
}

int	execute_command2(t_data *data, int fd_pipe[2], char **env)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open(data->files[1], O_WRONLY | O_TRUNC | O_CREAT, 0600);
	if (fd < 0)
		return (1);
	dup2(fd_pipe[1], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	while (data->path[i])
	{
		str = strjoin_pipex(data->path[i++], data->cmd[0]);
		if (!access(str, X_OK))
		{
			if ((execve(str, data->cmd2, env)) == -1)
			{
				free(str);
				return (1);
			}
		}
		free(str);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:48:55 by bchabot           #+#    #+#             */
/*   Updated: 2022/10/24 18:30:50 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	execute_cmds(char *str, char **cmd, char **envp)
{
	if (execve(str, cmd, envp) == -1)
	{
		error_cmd(cmd[0]);
		return (errno);
	}
	return (0);
}

int	first_cmd(t_data *data, int fd_pipe[2], char **envp)
{
	int		fd;
	char	*str;

	fd = open(data->files[0], O_RDONLY);
	if (fd < 0)
	{
		error_file(data->files[0], errno);
		return (errno);
	}
	dup2(fd, STDIN_FILENO);
	dup2(fd_pipe[1], STDOUT_FILENO);
	close(fd_pipe[0]);
	str = get_path(data, data->cmd[0]);
	if (!str)
	{
		error_cmd(data->cmd[0]);
		return (errno);
	}
	if (execute_cmds(str, data->cmd, envp))
		return (errno);
	close(fd);
	free(str);
	return (0);
}

int	second_cmd(t_data *data, int fd_pipe[2], char **envp)
{
	char	*str;
	int		fd;

	fd = open(data->files[1], O_WRONLY | O_TRUNC | O_CREAT, 0600);
	if (fd < 0)
	{
		error_file(data->files[1], errno);
		return (errno);
	}
	dup2(fd_pipe[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd_pipe[1]);
	str = get_path(data, data->cmd2[0]);
	if (!str)
	{
		error_cmd(data->cmd2[0]);
		return (errno);
	}
	if (execute_cmds(str, data->cmd2, envp))
		return (errno);
	close(fd);
	free(str);
	return (0);
}

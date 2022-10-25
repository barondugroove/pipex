/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:48:55 by bchabot           #+#    #+#             */
/*   Updated: 2022/10/25 16:02:31 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	execute_cmds(char *str, char **cmd, char **envp)
{
	if (access(str, X_OK) != 0)
		return (errno);
	if (execve(str, cmd, envp) == -1)
	{
		error_cmd(cmd[0]);
		return (1);
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
		free_struct(data);
		close(fd_pipe[0]);
		exit (1);
	}
	dup2(fd, STDIN_FILENO);
	dup2(fd_pipe[1], STDOUT_FILENO);
	ft_close(fd_pipe[0], fd);
	str = get_path(data, data->cmd[0]);
	if (!str)
	{
		error_cmd(data->cmd[0]);
		ft_close(fd_pipe[0], fd);
		free_struct(data);
		exit (1);
	}
	execute_cmds(str, data->cmd, envp);
	free(str);
	exit (1);
}

int	second_cmd(t_data *data, int fd_pipe[2], char **envp)
{
	char	*str;
	int		fd;

	fd = open(data->files[1], O_WRONLY | O_TRUNC | O_CREAT, 0600);
	if (fd < 0)
	{
		error_file(data->files[1], errno);
		free_struct(data);
		close(fd_pipe[1]);
		exit (1);
	}
	dup2(fd_pipe[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	ft_close(fd_pipe[1], fd);
	str = get_path(data, data->cmd2[0]);
	if (!str)
	{
		error_cmd(data->cmd2[0]);
		ft_close(fd_pipe[1], fd);
		free_struct(data);
		exit (1);
	}
	execute_cmds(str, data->cmd2, envp);
	free(str);
	exit (1);
}

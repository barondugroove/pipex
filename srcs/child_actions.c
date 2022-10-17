/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:48:55 by bchabot           #+#    #+#             */
/*   Updated: 2022/10/17 20:13:46 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	execute_command1(t_data *data, int fd_pipe[2], char **envp)
{
	int		fd;
	char	*str;

	fd = open(data->files[0], O_RDONLY);
	if (fd < 0)
		return (1);
	dup2(fd, STDIN_FILENO);
	dup2(fd_pipe[1], STDOUT_FILENO);
	close(fd_pipe[0]);
	str = get_path(data, data->cmd[0]);
	if (!access(str, X_OK))
	{
		if ((execve(str, data->cmd, envp)) == -1)
		{
			free(str);
			return (1);
		}
	}
	free(str);
	return (0);
}

int	execute_command2(t_data *data, int fd_pipe[2], char **envp)
{
	char	*str;
	int		fd;

	fd = open(data->files[1], O_WRONLY | O_TRUNC | O_CREAT, 0600);
	if (fd < 0)
		return (1);
	dup2(fd, STDOUT_FILENO);
	dup2(fd_pipe[0], STDIN_FILENO);
	close(fd_pipe[1]);
	close(fd);
	str = get_path(data, data->cmd2[0]);
	if (!access(str, X_OK))
	{
		if ((execve(str, data->cmd2, envp)) == -1)
		{
			free(str);
			return (1);
		}
	}
	free(str);
	return (0);
}

void	ft_error(char *msg, t_data *data)
{
	perror(msg);
	free_struct(data);
	exit(1);
}

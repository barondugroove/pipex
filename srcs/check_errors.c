/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:34:20 by bchabot           #+#    #+#             */
/*   Updated: 2022/10/04 19:40:58 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_file_ok(t_data *data)
{
	int	fds[2];

	fds[0] = open(data->files[0], O_RDONLY);
	if (fds[0] == -1)
	{
		close(fds[0]);
		return (0);
	}
	fds[1] = open(data->files[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fds[1] == -1)
	{
		close(fds[0]);
		close(fds[1]);
		return (0);
	}
	close(fds[0]);
	close(fds[1]);
	return (1);
}

int	is_cmd_ok(t_data *data, int x)
{
	char	*str;

	if (x == 0)
		str = strjoin_pipex(data->path, data->cmd[0]);
	else
		str = strjoin_pipex(data->path, data->cmd[1]);
	if ((access(str, X_OK) == -1))
	{
		free(str);
		return (0);
	}
	else
	{
		free(str);
		return (1);
	}
}


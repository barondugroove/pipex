/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:46:53 by bchabot           #+#    #+#             */
/*   Updated: 2022/10/17 20:07:14 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	check_error_files(char *file, int s)
{
	int	fd;

	if (s)
		fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0600);
	else
		fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}

int	check_error_cmd(t_data *data, char *cmd)
{
	char	*str;

	if (!cmd)
		return (1);
	if (cmd[0] == '/' || cmd[0] == '.')
	{
		str = ft_strdup(cmd);
		if (!access(str, X_OK))
		{
			free(str);
			return (0);
		}
		free(str);
		return (1);
	}
	else
	{
		str = get_path(data, cmd);
		if (!access(str, X_OK))
		{
			free(str);
			return (0);
		}
	}
	free(str);
	return (1);
}

int	check_errors(t_data *data)
{
	if (check_error_cmd(data, data->cmd[0]) && check_error_cmd(data, data->cmd2[0]))
		ft_error("Both commands are undoable.\n", data);
	if ((check_error_cmd(data, data->cmd2[0])) || check_error_files(data->files[1], 1))
		ft_error("Outfile or second command is erroneous.\n", data);
	if (check_error_files(data->files[0], 0) || check_error_cmd(data, data->cmd[0]))
		return (1);
	return (0);
}

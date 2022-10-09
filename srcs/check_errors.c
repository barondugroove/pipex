/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:46:53 by bchabot           #+#    #+#             */
/*   Updated: 2022/10/09 19:00:10 by bchabot          ###   ########.fr       */
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
	int		i;
	char	*str;

	i = 0;
	if (cmd[0] == '/' || cmd[0] == '.')
	{
		str = ft_strdup(cmd);
		if (access(str, X_OK) == -1)
		{
			free(str);
			return (1);
		}
		return (0);
	}
	else
	{
		while (data->path[i])
		{
			str = strjoin_pipex(data->path[i++], cmd);
			if (access(str, X_OK) == -1)
			{
				free(str);
				return (1);
			}
			free(str);
		}
	}
	return (0);
}

int	check_errors(t_data *data)
{
	if (check_error_cmd(data, data->cmd[0]) && check_error_cmd(data, data->cmd2[0]))
	{
		ft_printf("Both commands are undoable.\n");
		free_struct(data);
		return (1);
	}
	if ((check_error_cmd(data, data->cmd2[0])))
	{
		ft_printf("Second command is undoable.\n");
		free_struct(data);
		return (2);
	}
	if (check_error_files(data->files[0], 0) || check_error_cmd(data, data->cmd[0]))
	{
	//	free(data->cmd);
	//	free(data->file[0]);
		// exec cmd2
	}
	return (0);
}

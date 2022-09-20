/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:34:20 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/20 22:02:41 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_file_ok(t_data *data)
{
	int	fd[2];

	fd[0] = open(data->files[0], O_RDONLY);
	if (fd[0] == -1)
		return (0);
	open(data->files[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	return (1);
}

int	is_cmd_ok(t_data *data)
{
	while (i < 2)
	{
		if (access(data->cmd[1], F_OK) == -1)
			return (0);
	}
	return (1);
}

int	check_errors(t_data *data)
{
	if (!is_file_ok(data))
	{
		write(2, "Error files\n", 15);
		return (1);
	}
	if (!is_cmd_ok(data))
	{
		write(2, "Error commands\n", 15);
		return (1);
	}
	return (0);
}

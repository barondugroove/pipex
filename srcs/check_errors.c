/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:34:20 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/28 20:04:42 by bchabot          ###   ########.fr       */
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
	fds[1] = open(data->files[1], O_WRONLY | O_TRUNC | O_CREAT, 0600);
	if (fds[1] == -1)
	{
		close(fds[0]);
		return (0);
	}
	close(fds[0]);
	close(fds[1]);
	return (1);
}

void	check_errors(t_data *data)
{
	if (!is_file_ok(data))
	{
		write(2, "Error\n", 6);
		ft_free_files(data);
		exit(0);
	}
}

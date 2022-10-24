/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:11:57 by bchabot           #+#    #+#             */
/*   Updated: 2022/10/24 21:39:54 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_close(int fd, int fd2)
{
	close(fd);
	close(fd2);
	return ;
}

void	free_struct(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmd[i])
		free(data->cmd[i++]);
	free(data->cmd);
	i = 0;
	while (data->cmd2[i])
		free(data->cmd2[i++]);
	free(data->cmd2);
	i = 0;
	while (data->path[i])
		free(data->path[i++]);
	free(data->path);
}

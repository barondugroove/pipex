/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:27:12 by bchabot           #+#    #+#             */
/*   Updated: 2022/10/01 16:49:29 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_files(t_data *data)
{
	if (data->files[0])
		free(data->files[0]);
	if (data->files[1])
		free(data->files[1]);
	free(data->files);
}

void	ft_free_struct(t_data *data)
{
	int	i;

	i = 0;
	if (data->cmd)
		while (data->cmd[i])
			free(data->cmd[i++]);
	i = 0;
	if (data->cmd2)
		while (data->cmd2[i])
			free(data->cmd2[i++]);
	if (data->path)
		free(data->path);
	free(data);
}

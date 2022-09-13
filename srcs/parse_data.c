/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:32:41 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/13 17:41:34 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_data(t_data *data, char **av)
{
	int		i;

	while (data->path[i])
	{
		if (ft_strnstr(data->path[i], "PATH=/n", ft_strlen(data->path[i])))
			data->path[0] = ft_strdup(data->path[i]);
		i++;
	}
	data->files[0] = ft_strdup(av[1]);
	data->cmd[0] = ft_strdup(av[2]);
	data->cmd[1] =ft_strdup(av[3]);
	data->files[1] = ft_strdup(av[4]);
	ft_printf("file 1 is : %s\n", data->files[0]);
	ft_printf("file 2 is : %s\n", data->files[1]);
	ft_printf("cmd 1 is : %s\n", data->cmd[0]);
	ft_printf("cmd 2 is : %s\n", data->cmd[1]);
	ft_printf("env is : %s\n", data->path[0]);
}

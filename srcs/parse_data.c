/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:32:41 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/20 16:14:36 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_data(t_data *data, char **av, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=/n", ft_strlen(env[i])))
		{
				data->path = malloc(sizeof(char) * ft_strlen(env[i]) + 1);
				data->path = ft_split(env[i], ':');
		}
		i++;
	}
	data->files[0] = ft_strdup(av[1]);
	data->cmd = ft_split(av[2], ' ');
	data->cmd2 = ft_split(av[3], ' ');
	data->files[1] = ft_strdup(av[4]);
	ft_printf("file 1 is : %s\n", data->files[0]);
	ft_printf("file 2 is : %s\n", data->files[1]);
	i = 0;
	while (i < 2)
	{
		ft_printf("cmd 1 is : %s\n", data->cmd[i]);
		ft_printf("cmd 2 is : %s\n", data->cmd2[i++]);
	}
	i = 0;
	while (data->path[i])
	{
		ft_printf("env is : %s\n", data->path[i++]);
	}
}

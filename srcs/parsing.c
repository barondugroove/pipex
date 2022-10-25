/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:29:30 by bchabot           #+#    #+#             */
/*   Updated: 2022/10/25 16:30:29 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	parse_data(t_data *data, char **av, char **envp)
{
	int	i;

	i = 0;
	data->files[0] = av[1];
	data->files[1] = av[4];
	data->cmd = ft_split(av[2], ' ' );
	data->cmd2 = ft_split(av[3], ' ' );
	if (data->cmd[0] == NULL)
		error_cmd("");
	if (data->cmd2[0] == NULL)
		error_cmd("");
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=/", ft_strlen("PATH=/")))
			data->path = ft_split(envp[i], ':');
		i++;
	}
	return ;
}

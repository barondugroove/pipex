/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:32:41 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/28 20:27:24 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_correct_path(t_data *data, char **env)
{
	char	**tab;
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=/n", ft_strlen(env[i])))
		{
			tab = ft_split(env[i], ':');
			while (tab[x])
			{
				if ((access(strjoin_pipex(tab[x], data->cmd[0]), F_OK | R_OK) != -1))
				{
					data->path = ft_strdup(tab[x]);
					free(tab[x]);
					free(tab);
					return ;
				}
				free(tab[x++]);
			}
		}
		i++;
	}
	free(tab);
}

void	parse_data(t_data *data, char **av, char **env)
{
//	int	i;

//	i = 0;

	data->files[0] = ft_strdup(av[1]);
	data->files[1] = ft_strdup(av[4]);
	if (!is_file_ok(data))
	{
		free(data->files[0]);
		free(data->files[1]);
		write(2, "Error\n", 6);
		exit(0);
	}
	data->env = env;
	data->cmd = ft_split(av[2], ' ');
	data->cmd2 = ft_split(av[3], ' ');
	check_errors(data);
	get_correct_path(data, env);
/*	ft_printf("final path is : %s\n", data->path);
	ft_printf("file 1 is : %s\n", data->files[0]);
	ft_printf("file 2 is : %s\n", data->files[1]);
	i = 0;
	while (i < 2)
	{
		ft_printf("cmd 1 is : %s\n", data->cmd[i]);
		ft_printf("cmd 2 is : %s\n", data->cmd2[i++]);
	}
	ft_printf("\n");*/
}

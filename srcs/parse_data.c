/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:32:41 by bchabot           #+#    #+#             */
/*   Updated: 2022/10/01 19:35:46 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_correct_path(t_data *data, char **env)
{
	char	**tab;
	int		i;
	int		x;
	char	*str;

	i = 0;
	x = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=/n", ft_strlen(env[i])))
		{
			tab = ft_split(env[i], ':');
			while (tab[x])
			{
				str = strjoin_pipex(tab[x], data->cmd[0]);
				if ((access(str, F_OK | R_OK) != -1))
				{
					free(str);
					data->path = ft_strdup((const char *)tab[x]);
					while (tab[x])
						free(tab[x++]);
					free(tab);
					return ;
				}
				free(str);
				free(tab[x++]);
			}
		}
		i++;
	}
	free(tab);
}

void	parse_data(t_data *data, char **av, char **env)
{
	data->files[0] = ft_strdup((const char *)av[1]);
	data->files[1] = ft_strdup((const char *)av[4]);
	if (!is_file_ok(data))
		free(data->files[0]);
	data->env = env;
	data->cmd = ft_split(av[2], ' ');
	data->cmd2 = ft_split(av[3], ' ');
	get_correct_path(data, env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:32:41 by bchabot           #+#    #+#             */
/*   Updated: 2022/10/04 19:51:36 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_correct_path(t_data *data, char **env, int y)
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
				str = strjoin_pipex(tab[x], data->cmd[y]);
				if ((access(str, X_OK) != -1))
				{
					free(str);
					data->path = ft_strdup((const char *)tab[x]);
					while (tab[x])
						free(tab[x++]);
					free(tab);
					return (0);
				}
				free(str);
				free(tab[x++]);
			}
		}
		i++;
	}
	free(tab);
	return (1);
}

int	parse_data(t_data *data, char **av, char **env)
{
	data->files[0] = ft_strdup((const char *)av[1]);
	data->files[1] = ft_strdup((const char *)av[4]);
	if (!is_file_ok(data))
		free(data->files[0]);
	data->env = env;
	data->cmd = ft_split(av[2], ' ');
	data->cmd2 = ft_split(av[3], ' ');
	if (get_correct_path(data, env, 0))
		get_correct_path(data, env, 1);
	return (0);
}

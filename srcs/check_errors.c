/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:34:20 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/28 16:40:22 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_file_ok(t_data *data)
{
	int	fds[2];

	fds[0] = open(data->files[0], O_RDONLY);
	if (fds[0] == -1)
		return (0);
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
					return ;
				}
				x++;
			}
		}
		i++;
	}
}

int	check_errors(t_data *data)
{
	if (!is_file_ok(data))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

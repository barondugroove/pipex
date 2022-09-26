/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:34:20 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/26 15:32:35 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_file_ok(t_data *data)
{
	int	fd[2];

	fd[0] = open(data->files[0], O_RDONLY);
	if (fd[0] == -1)
		return (0);
	open(data->files[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	return (1);
}

int	is_cmd_ok(t_data *data)
{
	if (access(data->files[0], F_OK) == -1)
		return (0);
	if (access(data->files[1], F_OK) == -1)
		return (0);
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
		write(2, "Error files\n", 15);
		return (1);
	}
	if (!is_cmd_ok(data))
	{
		write(2, "Error commands\n", 15);
		return (1);
	}
	return (0);
}

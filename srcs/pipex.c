/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:15:48 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/13 17:50:50 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <string.h>

int	main(int ac, char **av, char **env)
{
	t_data	data;
	int		i;
	int		pid;
	int		fd[2];
	char	**tab;
	
	i = 0;
	data.path = env;
	if (pipe(fd) == -1)
		return (1);
	while (i < 2)
	{
		data.files = malloc(sizeof(char *) * 2);
		data.cmd = malloc(sizeof(char *) * 2);
		i++;
	}
	if (ac == 5)
		parse_data(&data, av);
	pid = fork();
	if (pid == -1)
		write(2, "ERROR\n", 6);
	else if (pid == 0)
	{
		if (open(data.files[0], O_RDONLY, 1) == -1)
			return (1);
	//	dup2(fd[0], STDOUT_FILENO);
		tab = ft_split(data.path[0], ':');
		i = 0;
		while (tab[i])
			ft_printf("%s\n", tab[i++]);
	//	execve(strcat(tab[0], data.cmd[0]), ft_split(data.cmd[0], ' '), data.path); 
	}
}

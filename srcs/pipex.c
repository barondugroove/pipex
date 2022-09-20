/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:15:48 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/20 19:45:28 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;
	int		i;
	//int		pid;
	//int		fd[2];
	//int		x;

	i = 0;
	//x = 100;
	//if (pipe(fd) == -1)
	//	return (1);
	while (i < 2)
	{
		data.files = malloc(sizeof(char *) * 2);
		data.cmd = malloc(sizeof(char *) * 2);
		i++;
	}
	if (ac == 5)
		parse_data(&data, av, env);
	check_errors(&data);
	/*pid = fork();
	if (pid == -1)
	{
		write(2, "ERROR\n", 6);
		return (1);
	}
	if (pid == 0)
	{
		close(fd[0]);
		if (open(data.files[0], O_RDONLY, 1) == -1)
			return (1);
		write(fd[1], &x, 10);
		close(fd[1]);
	}
	else
	{
		int str2;

		read(fd[0], &str2, 10);
		ft_printf("%d\n", str2);
		close(fd[1]);
	}*/
	return (0);
}

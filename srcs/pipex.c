/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:21:53 by bchabot           #+#    #+#             */
/*   Updated: 2022/10/09 18:56:55 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_data(t_data *data)
{
	int	i;

	i = 0;
	ft_printf("%s\n", data->files[0]);
	ft_printf("%s\n", data->cmd[0]);
	ft_printf("%s\n", data->cmd2[0]);
	ft_printf("%s\n", data->files[1]);
	while (data->path[i])
		ft_printf("%s\n", data->path[i++]);
	return ;
}

void	pipex(char **av, char **env)
{
	t_data	data;

	parse_data(&data, av, env);
	check_errors(&data);
//	print_data(&data);
//	free_struct(&data);
	//exec cmd2
}

int	main(int ac, char **av, char **env)
{
	if (ac == 5)
		pipex(av, env);
	else
	{
		perror("Wrong number of arguments. Please try again.");
		return (1);
	}
	return (0);
}

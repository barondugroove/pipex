/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:46:53 by bchabot           #+#    #+#             */
/*   Updated: 2022/10/18 19:59:36 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	check_error_files(char *file, int s)
{
	int	fd;

	if (s)
		fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0600);
	else
		fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}

int	check_error_cmd(t_data *data, char *cmd)
{
	char	*str;

	if (!cmd)
		return (1);
	str = get_path(data, cmd);
	if (!str)
	{
		free(str);
		return (1);
	}
	else if (!access(str, X_OK))
	{
		free(str);
		return (0);
	}
	return (1);
}

int	check_errors(t_data *data)
{
	if (check_error_cmd(data, data->cmd[0]) && check_error_cmd(data, data->cmd2[0]))
	{
		ft_error_command(data, data->cmd[0]);
		ft_error_command(data, data->cmd2[0]);
		free_struct(data);
		exit(1);
	}
	if (check_error_cmd(data, data->cmd[0]))
	{
		ft_error_command(data, data->cmd[0]);
		return (1);
	}
	if (check_error_cmd(data, data->cmd2[0]))
		ft_error_command(data, data->cmd2[0]);
	if (check_error_files(data->files[1], 1))
		ft_error_file(data, data->files[1]);
	if (check_error_files(data->files[0], 0))
	{
		ft_error_file(data, data->files[0]);
		return (1);
	}
	return (0);
}

void	ft_error_command(t_data *data, char *cmd)
{
	(void)data;
	ft_printf("command not found: %s\n", cmd);
}

void	ft_error_file(t_data *data, char *file)
{
	(void)data;
	ft_putstr_fd("permission denied: ", 2);
	ft_putstr_fd(file, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}

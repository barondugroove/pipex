/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:46:53 by bchabot           #+#    #+#             */
/*   Updated: 2022/10/24 18:30:49 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_cmd(char *cmd)
{
	ft_putstr_fd("command not found: ", 2);
	ft_putendl_fd(cmd, 2);
}

void	error_file(char *file, int errnum)
{
	ft_putstr_fd(strerror(errnum), 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(file, 2);
}

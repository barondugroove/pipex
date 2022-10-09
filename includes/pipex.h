/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:26:12 by bchabot           #+#    #+#             */
/*   Updated: 2022/10/09 18:47:45 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_data {
	char	**cmd;
	char	**cmd2;
	char	*files[2];
	char	**path;
}	t_data;

// PARSING
void	parse_data(t_data *data, char **av, char **env);

// FREE_DATA
void	free_struct(t_data *data);
void	ft_free_files(t_data *data);

// CHECK_ERRORS
int		check_errors(t_data *data);
int		check_error_files(char *file, int s);
int		check_error_cmd(t_data *data, char *cmd);

int		execute_command1(t_data *data, int fd_pipe[2]);
int		execute_command2(t_data *data, int fd_pipe[2]);

// PIPEX_UTILS
char	*strjoin_pipex(char *str, char *av);
char	*strcat_pipex(char *dst, char *src);

#endif

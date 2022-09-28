/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:26:12 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/28 21:10:50 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_data {
	char	**cmd;
	char	**cmd2;
	char	*files[2];
	char	*path;
	char	**env;
}	t_data;

void	parse_data(t_data *data, char **av, char **env);
char	*strjoin_pipex(char *str, char *av);
void	check_errors(t_data *data);
int		is_file_ok(t_data *data);
char	*strcat_pipex(char *dst, char *src);
void	get_correct_path(t_data	*data, char **env);

void	ft_free_struct(t_data *data);
void	ft_free_files(t_data *data);

int		execute_command1(t_data *data, int fd_pipe[2], int fd_file[2]);
int		execute_command2(t_data *data, int fd_pipe[2], int fd_file[2]);

#endif

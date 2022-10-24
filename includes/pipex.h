/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:26:12 by bchabot           #+#    #+#             */
/*   Updated: 2022/10/24 18:35:12 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <errno.h>
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
void	parse_data(t_data *data, char **av, char **envp);

// FREE_DATA
void	free_struct(t_data *data);
void	ft_free_files(t_data *data);

// ERRORS
void	error_cmd(char *cmd);
void	error_file(char *file, int errnum);

// CHILD_ACTIONS
int		execute_cmds(char *str, char **cmd, char **envp);
int		first_cmd(t_data *data, int fd_pipe[2], char **envp);
int		second_cmd(t_data *data, int fd_pipe[2], char **envp);

// PIPEX_UTILS
char	*strjoin_pipex(char *str, char *av);
char	*strcat_pipex(char *dst, char *src);
char	*get_path(t_data *data, char *cmd);

#endif

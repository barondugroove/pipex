/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:26:12 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/27 16:31:12 by bchabot          ###   ########.fr       */
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
	char	**files;
	char	*path;
	char	**env;
}	t_data;

void	parse_data(t_data *data, char **av, char **env);
char	*strjoin_pipex(char *str, char *av);
int		check_errors(t_data *data);
char	*strcat_pipex(char *dst, char *src);
void	get_correct_path(t_data	*data, char **env);
void	ft_free(t_data *data);
t_data	*ft_set_data(void);

#endif

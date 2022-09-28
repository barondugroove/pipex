/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 21:36:26 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/28 15:58:40 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*strjoin_pipex(char *s1, char *s2)
{
	char	*str;
	int		length;

	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2) + 2;
	str = malloc(sizeof(char) * length);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, length);
	ft_strlcat(str, "/", length);
	ft_strlcat(str, s2, length);
	return (str);
}

char	*strcat_pipex(char *dst, char *src)
{
	size_t	dl;
	size_t	i;

	dl = ft_strlen(dst);
	i = 0;
	if (!*src)
		return (dst);
	dst[dl + 1] = '/';
	while (src[i])
	{
		dst[dl + i] = src[i];
		i++;
	}
	dst[dl + i] = '\0';
	return (dst);
}

void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmd[i])
		free(data->cmd[i++]);
	i = 0;
	while (data->cmd2[i])
		free(data->cmd2[i++]);
	free(data->env);
	free(data->files[0]);
	free(data->files[1]);
	free(data->path);
	free(data);
}

t_data	*ft_set_data(void)
{
	t_data	*stack;

	stack = malloc(sizeof(t_data));
	if (!stack)
		return (NULL);
	stack->path = NULL;
	stack->env = NULL;
	stack->files = malloc(sizeof(char *) * 2);
	stack->files[0] = malloc(sizeof(char));
	stack->files[1] = malloc(sizeof(char));
	stack->cmd = NULL;
	stack->cmd2 = NULL;
	return (stack);
}

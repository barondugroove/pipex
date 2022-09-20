/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:41:45 by bchabot           #+#    #+#             */
/*   Updated: 2022/09/20 11:46:07 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb >= 65536 || size >= 65536)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (ptr);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}

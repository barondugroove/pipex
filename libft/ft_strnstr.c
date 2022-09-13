/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:16:00 by bchabot           #+#    #+#             */
/*   Updated: 2022/04/01 20:13:32 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	x;
	size_t	y;

	if (*little == '\0')
		return ((char *)big);
	x = 0;
	while (big[x] && x < len)
	{
		if (big[x] == little[0])
		{
			y = 0;
			while (big[y] && big[x + y] == little[y]
				&& x + y < len)
			{
				y++;
				if (little[y] == '\0')
					return ((char *)big + x);
			}
		}
		x++;
	}
	return (NULL);
}

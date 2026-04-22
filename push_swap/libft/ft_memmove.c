/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:40:54 by mande-so          #+#    #+#             */
/*   Updated: 2025/11/03 18:11:36 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest2;
	const char	*src2;
	size_t		i;

	dest2 = (char *)dst;
	src2 = (const char *)src;
	i = 0;
	if (dst == src || len == 0)
		return (dst);
	if (dest2 > src2)
	{
		while (len-- > 0)
			dest2[len] = src2[len];
	}
	else
	{
		while (i < len)
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:54:24 by mande-so          #+#    #+#             */
/*   Updated: 2025/10/27 15:02:04 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	j;
	char	*s2;

	i = 0;
	while (s[i])
		i++;
	s2 = malloc(sizeof(char) * (i + 1));
	if (s2 == NULL)
		return (NULL);
	else
	{
		i = 0;
		j = 0;
		while (s[i])
		{
			s2[j] = s[i];
			i++;
			j++;
		}
		s2[j] = '\0';
	}
	return (s2);
}

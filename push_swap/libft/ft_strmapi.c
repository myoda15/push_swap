/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:09:55 by mande-so          #+#    #+#             */
/*   Updated: 2025/11/05 18:10:23 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapi;
	size_t	i;
	size_t	len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	mapi = malloc(sizeof(char) * (len + 1));
	if (!mapi)
		return (NULL);
	i = 0;
	while (i < len)
	{
		mapi[i] = f(i, s [i]);
		i++;
	}
	mapi[i] = '\0';
	return (mapi);
}

/* char	f(unsigned int i, char str)
{
	if (str >= 'a' && str <= 'z')
		str -= 32;
	return (str);
}

#include <stdio.h>

int	main()
{
	char	*str = "olamundo";
	printf("%s", ft_strmapi(str, f));
} */
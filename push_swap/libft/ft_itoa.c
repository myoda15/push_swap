/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:47:40 by mande-so          #+#    #+#             */
/*   Updated: 2025/11/05 18:09:34 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;
	long	nb;

	size = get_size(n);
	str = malloc(sizeof(char) * (size + 1));
	nb = n;
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[--size] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

/* int main(void)
{
    char *result;
    result = ft_itoa(-2147483648);
    printf("ft_itoa: %s\n", result);
    char *result1;
    result1 = itoa(-2147483648);
    printf("itoa: %s\n", result1);
} */

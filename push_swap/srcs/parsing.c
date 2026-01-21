/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:28:49 by mande-so          #+#    #+#             */
/*   Updated: 2026/01/20 23:41:11 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static long	ft_atol(char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static int	has_duplicates(char **argv, int count)
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	i = 1;
	while (i < count)
	{
		num1 = ft_atoi(argv[i]);
		j = i + 1;
		while (j < count)
		{
			num2 = ft_atoi(argv[j]);
			if (num1 == num2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	validate_args(int argc, char **argv)
{
	int		i;
	long	num;

	if (argc < 2)
		exit(0);
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			error_exit();
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			error_exit();
		i++;
	}
	if (has_duplicates(argv, argc))
		error_exit();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:28:36 by mande-so          #+#    #+#             */
/*   Updated: 2026/01/21 00:31:25 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	is_sorted(s_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_min(s_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->number;
	while (stack)
	{
		if (stack->number < min)
			min = stack->number;
		stack = stack->next;
	}
	return (min);
}

int	find_max(s_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->number;
	while (stack)
	{
		if (stack->number > max)
			max = stack->number;
		stack = stack->next;
	}
	return (max);
}

int	find_position(s_stack *stack, int value)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->number == value)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

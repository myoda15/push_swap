/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:28:33 by mande-so          #+#    #+#             */
/*   Updated: 2026/01/21 01:39:56 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

s_stack	*creat_stack(int number)
{
	s_stack	*stack;

	stack = malloc(sizeof(s_stack));
	if (!stack)
		return (NULL);
	stack->number = number;
	stack->index = 0;
	stack->next = NULL;
	return (stack);
}

void	add_first(s_stack **stack, s_stack *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	*stack = new;
}

int	stack_len(s_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

s_stack	*stack_last(s_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}

void	add_last(s_stack **stack, s_stack *new)
{
	s_stack *stack1;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	stack1 = stack_last(*stack);
	stack1->next = new;
}

void	stack_clear(s_stack **stack)
{
	s_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

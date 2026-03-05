/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:25:26 by mande-so          #+#    #+#             */
/*   Updated: 2026/01/20 00:34:55 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	reverse_rotate_down(s_stack **stack)
{
	s_stack	*last;
	s_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = stack_last(*stack);
	second_last = *stack;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	last->next = *stack;
	*stack = last;
	second_last->next = NULL;
}

void	rra(s_stack **a)
{
	reverse_rotate_down(a);
	write(1, "rra\n", 4);
}

void	rrb(s_stack **b)
{
	reverse_rotate_down(b);
	write(1, "rrb\n", 4);
}

void	rrr(s_stack **a, s_stack **b)
{
	reverse_rotate_down(a);
	reverse_rotate_down(b);
	write(1, "rrr\n", 4);
}

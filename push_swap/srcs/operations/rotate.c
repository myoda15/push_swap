/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:25:29 by mande-so          #+#    #+#             */
/*   Updated: 2026/01/20 23:41:22 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	rotate_up(s_stack **stack)
{
	s_stack	*first;
	s_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = stack_last(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(s_stack **a)
{
	rotate_up(a);
	write(1, "ra\n", 3);
}

void	rb(s_stack **b)
{
	rotate_up(b);
	write(1, "rb\n", 3);
}

void	rr(s_stack **a, s_stack **b)
{
	rotate_up(a);
	rotate_up(b);
	write(1, "rr\n", 3);
}

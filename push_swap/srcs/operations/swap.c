/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:23:36 by mande-so          #+#    #+#             */
/*   Updated: 2026/01/19 23:09:55 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	swap_top(s_stack **stack)
{
	s_stack	*first;
	s_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(s_stack **a)
{
	swap_top(a);
	write(1, "sa\n", 3);
}

void sb(s_stack **b)
{
	swap_top(b);
	write(1, "sb\n", 3);
}

void	ss(s_stack **a, s_stack **b)
{
	swap_top(a);
	swap_top(b);
	write(1, "ss\n", 3);
}

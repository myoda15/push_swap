/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 00:00:00 by mande-so          #+#    #+#             */
/*   Updated: 2026/01/21 01:45:50 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	push_silent(s_stack **src, s_stack **dest)
{
	s_stack	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

static void	rotate_silent(s_stack **stack)
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

static void	reverse_rotate_silent(s_stack **stack)
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

int	execute_operation(char *line, s_stack **a, s_stack **b)
{
	int	valid;

	valid = 1;
	if (ft_strncmp(line, "pa\n", 3) == 0)
		push_silent(b, a);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push_silent(a, b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate_silent(a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate_silent(b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
	{
		rotate_silent(a);
		rotate_silent(b);
	}
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		reverse_rotate_silent(a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		reverse_rotate_silent(b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
	{
		reverse_rotate_silent(a);
		reverse_rotate_silent(b);
	}
	else
		execute_swap_ops(line, a, b, &valid);
	return (valid);
}

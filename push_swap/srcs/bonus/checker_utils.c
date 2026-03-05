/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 00:00:00 by mande-so          #+#    #+#             */
/*   Updated: 2026/01/21 01:47:33 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	sa_silent(s_stack **a)
{
	s_stack	*first;
	s_stack	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
}

static void	sb_silent(s_stack **b)
{
	s_stack	*first;
	s_stack	*second;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
}

static void	ss_silent(s_stack **a, s_stack **b)
{
	sa_silent(a);
	sb_silent(b);
}

void	execute_swap_ops(char *line, s_stack **a, s_stack **b, int *valid)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa_silent(a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb_silent(b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss_silent(a, b);
	else
		*valid = 0;
}

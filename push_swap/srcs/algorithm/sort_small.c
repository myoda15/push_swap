/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:25:21 by mande-so          #+#    #+#             */
/*   Updated: 2026/04/14 17:05:10 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_two(t_stack **a)
{
	int	first;
	int	second;

	first = (*a)->number;
	second = (*a)->next->number;
	if (first > second)
		sa(a);
}

static void	sort_three_case_one(t_stack **a, int first, int second, int third)
{
	if (first < second && first < third && second > third)
	{
		sa(a);
		ra(a);
	}
	else if (first > second && first < third && second < third)
		sa(a);
}

static void	sort_three_case_two(t_stack **a, int first, int second, int third)
{
	if (first < second && first > third && second > third)
		rra(a);
	else if (first > second && first > third && second < third)
		ra(a);
	else if (first > second && first > third && second > third)
	{
		sa(a);
		rra(a);
	}
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->number;
	second = (*a)->next->number;
	third = (*a)->next->next->number;
	sort_three_case_one(a, first, second, third);
	sort_three_case_two(a, first, second, third);
}

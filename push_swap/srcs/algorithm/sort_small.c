/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:25:21 by mande-so          #+#    #+#             */
/*   Updated: 2026/01/21 00:58:01 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_two(s_stack **a)
{
	int	first;
	int	second;

	first = (*a)->number;
	second = (*a)->next->number;
	if (first > second)
		sa(a);
}

static void	sort_three_case_one(s_stack **a, int first, int second, int third)
{
	if (first < second && first < third && second > third)
	{
		sa(a);
		ra(a);
	}
	else if (first > second && first < third && second < third)
		sa(a);
}

static void	sort_three_case_two(s_stack **a, int first, int second, int third)
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

void	sort_three(s_stack **a)
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

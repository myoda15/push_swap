/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:23:52 by mande-so          #+#    #+#             */
/*   Updated: 2026/01/20 00:17:51 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	push(s_stack **src, s_stack **dest)
{
	s_stack	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

void	pa(s_stack **a, s_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(s_stack **a, s_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

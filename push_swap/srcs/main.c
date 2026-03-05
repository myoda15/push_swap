/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:01:06 by mande-so          #+#    #+#             */
/*   Updated: 2026/01/21 01:37:12 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	s_stack *a;
	s_stack *b;
	int		size;

	validate_args(argc, argv);
	a = init_stack_a(argc, argv);
	b = NULL;
	if (is_sorted(a))
	{
		stack_clear(&a);
		return (0);
	}
	size = stack_len(a);
	if (size == 2)
		sort_two(&a);
	else if (size == 3)
		sort_three(&a);
	else if (size == 4)
		sort_four(&a, &b);
	else if (size == 5)
		sort_five(&a, &b);
	else
		sort_large(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}

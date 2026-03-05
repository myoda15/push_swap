/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 00:00:00 by mande-so          #+#    #+#             */
/*   Updated: 2026/01/21 01:46:51 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	check_result(s_stack *a, s_stack *b)
{
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	s_stack	*a;
	s_stack	*b;
	char	*line;

	validate_args(argc, argv);
	a = init_stack_a(argc, argv);
	b = NULL;
	line = get_next_line(0);
	while (line)
	{
		if (!execute_operation(line, &a, &b))
		{
			free(line);
			stack_clear(&a);
			stack_clear(&b);
			error_exit();
		}
		free(line);
		line = get_next_line(0);
	}
	check_result(a, b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}

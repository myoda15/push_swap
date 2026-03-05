/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:26:57 by mande-so          #+#    #+#             */
/*   Updated: 2025/12/20 16:26:58 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

s_stack	*init_stack_a(int argc, char **argv)
{
	s_stack	*a;
	s_stack	*new;
	int		i;
	int		num;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		new = creat_stack(num);
		if (!new)
		{
			stack_clear(&a);
			error_exit();
		}
		add_last(&a, new);
		i++;
	}
	return (a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:26:57 by mande-so          #+#    #+#             */
/*   Updated: 2026/04/21 00:00:00 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*init_stack_a(char **args, int count)
{
	t_stack	*a;
	t_stack	*new;
	int		i;
	int		num;

	a = NULL;
	i = 0;
	while (i < count)
	{
		num = ft_atoi(args[i]);
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

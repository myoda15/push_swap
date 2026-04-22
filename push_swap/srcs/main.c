/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:01:06 by mande-so          #+#    #+#             */
/*   Updated: 2026/04/21 00:00:00 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
		sort_large(a, b);
}

static char	**get_args(int argc, char **argv, int *count)
{
	char	**args;

	if (argc == 1)
		exit(0);
	if (argc > 2)
		args = argv + 1;
	else
		args = ft_split(argv[1], ' ');
	if (!args)
		error_exit();
	*count = 0;
	while (args[*count])
		(*count)++;
	if (!*count && argc == 2)
	{
		free_split(args);
		error_exit();
	}
	return (args);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		count;

	args = get_args(argc, argv, &count);
	validate_args(args, count);
	a = init_stack_a(args, count);
	if (argc == 2)
		free_split(args);
	b = NULL;
	if (is_sorted(a))
	{
		stack_clear(&a);
		return (0);
	}
	sort(&a, &b, stack_len(a));
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}

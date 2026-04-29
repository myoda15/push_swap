/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:01:06 by mande-so          #+#    #+#             */
/*   Updated: 2026/04/28 20:00:00 by mande-so         ###   ########.fr       */
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

static char	*join_args(int argc, char **argv)
{
	char	*result;
	char	*temp;
	int		i;

	result = ft_strdup(argv[1]);
	i = 2;
	while (result && i < argc)
	{
		temp = ft_strjoin(result, " ");
		free(result);
		if (!temp)
			return (NULL);
		result = ft_strjoin(temp, argv[i]);
		free(temp);
		i++;
	}
	return (result);
}

static char	**get_args(int argc, char **argv, int *count)
{
	char	**args;
	char	*joined;

	if (argc == 1)
		exit(0);
	joined = join_args(argc, argv);
	if (!joined)
		error_exit();
	args = ft_split(joined, ' ');
	free(joined);
	if (!args)
		error_exit();
	*count = 0;
	while (args[*count])
		(*count)++;
	if (!*count)
	{
		free_split(args);
		error_exit();
	}
	return (args);
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		count;

	args = get_args(argc, argv, &count);
	if (!validate_args(args, count))
	{
		free_split(args);
		error_exit();
	}
	a = init_stack_a(args, count);
	free_split(args);
	if (!a)
		error_exit();
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

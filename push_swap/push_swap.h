/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:00:19 by mande-so          #+#    #+#             */
/*   Updated: 2026/01/21 01:46:51 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}					s_stack;

s_stack	*creat_stack(int number);
void	add_first(s_stack **stack, s_stack *new);
int	stack_len(s_stack *stack);
s_stack	*stack_last(s_stack *stack);
void	add_last(s_stack **stack, s_stack *new);
void	stack_clear(s_stack **stack);

void	sa(s_stack **a);
void	sb(s_stack **b);
void	ss(s_stack **a, s_stack **b);

void	pa(s_stack **a, s_stack **b);
void	pb(s_stack **a, s_stack **b);

void	ra(s_stack **a);
void	rb(s_stack **b);
void	rr(s_stack **a, s_stack **b);

void	rra(s_stack **a);
void	rrb(s_stack **b);
void	rrr(s_stack **a, s_stack **b);

void	error_exit(void);
void	validate_args(int argc, char **argv);
s_stack	*init_stack_a(int argc, char **argv);

int		is_sorted(s_stack *stack);
int		find_min(s_stack *stack);
int		find_max(s_stack *stack);
int		find_position(s_stack *stack, int value);

void	sort_two(s_stack **a);
void	sort_three(s_stack **a);
void	sort_four(s_stack **a, s_stack **b);
void	sort_five(s_stack **a, s_stack **b);
void	sort_large(s_stack **a, s_stack **b);

char	*get_next_line(int fd);
int		execute_operation(char *line, s_stack **a, s_stack **b);
void	execute_swap_ops(char *line, s_stack **a, s_stack **b, int *valid);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:46:18 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/27 11:08:19 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	int				cost_a;
	int				cost_b;
	struct s_node	*target;
	struct s_node	*next;
}	t_node;
typedef struct s_stack
{
	t_node	*head;
}	t_stack;
void	ft_push_swap(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack **stack_a, int type_bool);
void	sb(t_stack **stack_b, int type_bool);
void	ss(t_stack **stack_a, t_stack **stack_b, int type_bool);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a, int type_bool);
void	rb(t_stack **stack_b, int type_bool);
void	rr(t_stack **stack_a, t_stack **stack_b, int type_bool);
void	rra(t_stack **stack_a, int type_bool);
void	rrb(t_stack **stack_b, int type_bool);
void	rrr(t_stack **stack_a, t_stack **stack_b, int type_bool);
void	sort_two(t_stack *stack_a);
void	sort_three(t_stack *stack_a);
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	add_to_stack(t_stack *stack, int value);
void	free_stack(t_stack *stack);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
int		ft_abs(int x);
void	rot_a(t_stack **stack_a, int *ca);
void	rot_b(t_stack **stack_b, int *cb);
int		ft_check_digit(char *stack_s);
int		ft_check_av(int ac, char **av);
void	ft_split_stack(int ac, char **av, t_stack *stack_a);
void	check_dup(t_stack *stack_a);
void	error_exit(t_stack *stack_a);
void	free_split(char **split);
void	set_index(t_stack *stack_a);
void	position(t_stack *stack);
void	target(t_stack *stack_a, t_stack *stack_b);
void	cost(t_stack *stack_a, t_stack *stack_b);
void	bring_min_top(t_stack **stack_a);
void	do_move(t_stack *stack_a, t_stack *stack_b);
void	push_all(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack_a);
void	turk_sort(t_stack *stack_a, t_stack *stack_b);
#endif

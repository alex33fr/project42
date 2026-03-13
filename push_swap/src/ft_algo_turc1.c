/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_turc1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:30:28 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/27 14:39:41 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rot_both(t_stack **stack_a, t_stack **stack_b, int *ca, int *cb)
{
	while (*ca > 0 && *cb > 0)
	{
		rr(stack_a, stack_b, 1);
		(*ca)--;
		(*cb)--;
	}
	while (*ca < 0 && *cb < 0)
	{
		rrr(stack_a, stack_b, 1);
		(*ca)++;
		(*cb)++;
	}
}

void	push_all(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = stack_size(stack_a);
	while (size > 3)
	{
		pb(&stack_a, &stack_b);
		size--;
	}
}

void	do_move(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	t_node	*best;
	int		best_cost;
	int		ca;
	int		cb;

	current = stack_b->head;
	best = current;
	best_cost = 2147483647;
	while (current)
	{
		int	ca_abs;
		int	cb_abs;
		int	effective_cost;

		ca_abs = ft_abs(current->cost_a);
		cb_abs = ft_abs(current->cost_b);
		if ((current->cost_a >= 0 && current->cost_b >= 0)
			|| (current->cost_a <= 0 && current->cost_b <= 0))
			effective_cost = (ca_abs > cb_abs) ? ca_abs : cb_abs;
		else
			effective_cost = ca_abs + cb_abs;
		if (effective_cost < best_cost)
		{
			best_cost = effective_cost;
			best = current;
		}
		current = current->next;
	}
	ca = best->cost_a;
	cb = best->cost_b;
	rot_both(&stack_a, &stack_b, &ca, &cb);
	rot_a(&stack_a, &ca);
	rot_b(&stack_b, &cb);
	pa(&stack_a, &stack_b);
}

static int	get_min_pos_index(t_stack *stack_a)
{
	t_node	*current;
	int		min_index;
	int		min_pos;
	int		i;

	current = stack_a->head;
	min_index = current->index;
	min_pos = 0;
	i = 0;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

void	rotate(t_stack *stack_a)
{
	int	min_pos;
	int	size;

	min_pos = get_min_pos_index(stack_a);
	size = stack_size(stack_a);
	if (min_pos <= size / 2)
		while (min_pos-- > 0)
			ra(&stack_a, 1);
	else
		while (min_pos++ < size)
			rra(&stack_a, 1);
}

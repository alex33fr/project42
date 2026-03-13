/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_turc1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:30:28 by aprivalo          #+#    #+#             */
/*   Updated: 2026/03/13 12:35:44 by aprivalo         ###   ########.fr       */
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

static int	get_effective_cost(t_node *node)
{
	int	ca_abs;
	int	cb_abs;

	ca_abs = ft_abs(node->cost_a);
	cb_abs = ft_abs(node->cost_b);
	if ((node->cost_a >= 0 && node->cost_b >= 0)
		|| (node->cost_a <= 0 && node->cost_b <= 0))
	{
		if (ca_abs > cb_abs)
			return (ca_abs);
		return (cb_abs);
	}
	return (ca_abs + cb_abs);
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
		if (get_effective_cost(current) < best_cost)
		{
			best_cost = get_effective_cost(current);
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

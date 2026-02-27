/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_turc2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:00:27 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/27 11:12:57 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*get_min_index_node(t_stack *stack_a)
{
	t_node	*min;
	t_node	*current;

	min = stack_a->head;
	current = stack_a->head;
	while (current)
	{
		if (current->index < min->index)
			min = current;
		current = current->next;
	}
	return (min);
}

void	set_index(t_stack *stack_a)
{
	t_node	*current;
	t_node	*cmp;
	int		rank;

	current = stack_a->head;
	while (current)
	{
		rank = 0;
		cmp = stack_a->head;
		while (cmp)
		{
			if (cmp->value < current->value)
				rank++;
			cmp = cmp->next;
		}
		current->index = rank;
		current = current->next;
	}
}

void	position(t_stack *stack)
{
	t_node	*current;
	int		i;

	current = stack->head;
	i = 0;
	while (current)
	{
		current->pos = i;
		current = current->next;
		i++;
	}
}

void	target(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*b;
	t_node	*a;
	t_node	*best;

	b = stack_b->head;
	while (b)
	{
		best = NULL;
		a = stack_a->head;
		while (a)
		{
			if (a->index > b->index && (!best || a->index < best->index))
				best = a;
			a = a->next;
		}
		if (!best)
			best = get_min_index_node(stack_a);
		b->target = best;
		b = b->next;
	}
}

void	cost(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*b;
	int		sa;
	int		sb;

	sa = stack_size(stack_a);
	sb = stack_size(stack_b);
	b = stack_b->head;
	while (b)
	{
		b->cost_b = b->pos;
		if (b->pos > sb / 2)
			b->cost_b = b->pos - sb;
		b->cost_a = b->target->pos;
		if (b->target->pos > sa / 2)
			b->cost_a = b->target->pos - sa;
		b = b->next;
	}
}

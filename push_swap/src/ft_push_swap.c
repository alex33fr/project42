/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 12:07:05 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/27 11:12:36 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_pos(t_stack *stack_a)
{
	t_node	*tmp;
	int		min;
	int		pos;
	int		i;

	tmp = stack_a->head;
	min = tmp->value;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	bring_min_top(t_stack **stack_a)
{
	int	pos;
	int	size;

	pos = get_min_pos(*stack_a);
	size = stack_size(*stack_a);
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(stack_a, 1);
	else
		while (pos++ < size)
			rra(stack_a, 1);
}

void	turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	set_index(stack_a);
	push_all(stack_a, stack_b);
	sort_three(stack_a);
	while (stack_b->head)
	{
		position(stack_a);
		position(stack_b);
		target(stack_a, stack_b);
		cost(stack_a, stack_b);
		do_move(stack_a, stack_b);
	}
	rotate(stack_a);
}

void	ft_push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	if (is_sorted(stack_a))
		return ;
	size = stack_size(stack_a);
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
		turk_sort(stack_a, stack_b);
}

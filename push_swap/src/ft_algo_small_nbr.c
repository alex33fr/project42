/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_small_nbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:51:25 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/25 17:28:23 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *  Sort 2 elements
 */
void	sort_two(t_stack *stack_a)
{
	if (stack_a->head->value > stack_a->head->next->value)
		sa(&stack_a, 1);
}

/**
 *  Sort 3 elements in at most 2 moves
 */
void	sort_three(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->head->value;
	b = stack_a->head->next->value;
	c = stack_a->head->next->next->value;
	if (a > b && b < c && a < c)
		sa(&stack_a, 1);
	else if (a > b && b > c)
	{
		sa(&stack_a, 1);
		rra(&stack_a, 1);
	}
	else if (a > b && b < c && a > c)
		ra(&stack_a, 1);
	else if (a < b && b > c && a < c)
	{
		sa(&stack_a, 1);
		ra(&stack_a, 1);
	}
	else if (a < b && b > c && a > c)
		rra(&stack_a, 1);
}

/**
 *  Sort 4: push min to B, sort 3, pull back
 */
void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	bring_min_top(&stack_a);
	pb(&stack_a, &stack_b);
	sort_three(stack_a);
	pa(&stack_a, &stack_b);
}

/**
 *  Sort 5: push 2 mins to B, sort 3, pull back
 */
void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	bring_min_top(&stack_a);
	pb(&stack_a, &stack_b);
	bring_min_top(&stack_a);
	pb(&stack_a, &stack_b);
	sort_three(stack_a);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
}

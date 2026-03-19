/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_turc3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 20:20:17 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/27 11:12:02 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *  Returns absolute value of x
 */
int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

/**
 *  Rotate A by cost_a steps
 */
void	rot_a(t_stack **stack_a, int *ca)
{
	while (*ca > 0)
	{
		ra(stack_a, 1);
		(*ca)--;
	}
	while (*ca < 0)
	{
		rra(stack_a, 1);
		(*ca)++;
	}
}

/**
 *  Rotate B by cost_b steps
 */
void	rot_b(t_stack **stack_b, int *cb)
{
	while (*cb > 0)
	{
		rb(stack_b, 1);
		(*cb)--;
	}
	while (*cb < 0)
	{
		rrb(stack_b, 1);
		(*cb)++;
	}
}

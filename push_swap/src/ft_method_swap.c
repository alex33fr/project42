/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_method_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:26:58 by aprivalo          #+#    #+#             */
/*   Updated: 2026/03/19 16:04:18 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *  Swap top two of A
 */
void	sa(t_stack **s_sa, int type_bool)
{
	t_node	*first;
	t_node	*second;

	if (*s_sa && (*s_sa)->head && (*s_sa)->head->next)
	{
		first = (*s_sa)->head;
		second = first->next;
		first->next = second->next;
		second->next = first;
		(*s_sa)->head = second;
		if (type_bool == 1)
			ft_printf("sa\n");
	}
}

/**
 *  Swap top two of B
 */
void	sb(t_stack **s_sb, int type_bool)
{
	t_node	*first;
	t_node	*second;

	if (*s_sb && (*s_sb)->head && (*s_sb)->head->next)
	{
		first = (*s_sb)->head;
		second = first->next;
		first->next = second->next;
		second->next = first;
		(*s_sb)->head = second;
		if (type_bool == 1)
			ft_printf("sb\n");
	}
}

/**
 *  Swap top two of both stacks
 */
void	ss(t_stack **s_sa, t_stack **s_sb, int type_bool)
{
	if (*s_sa && *s_sb
		&& (*s_sa)->head && (*s_sa)->head->next
		&& (*s_sb)->head && (*s_sb)->head->next)
	{
		sa(s_sa, 0);
		sb(s_sb, 0);
		if (type_bool == 1)
			ft_printf("ss\n");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_method_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:28:14 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/25 17:16:50 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **s_sa, int type_bool)
{
	t_node	*first;
	t_node	*current;

	if ((*s_sa)->head && (*s_sa)->head->next)
	{
		first = (*s_sa)->head;
		current = first;
		while (current->next != NULL)
			current = current->next;
		current->next = first;
		(*s_sa)->head = first->next;
		first->next = NULL;
		if (type_bool == 1)
			ft_printf("ra\n");
	}
}

void	rb(t_stack **s_sb, int type_bool)
{
	t_node	*first;
	t_node	*current;

	if ((*s_sb)->head && (*s_sb)->head->next)
	{
		first = (*s_sb)->head;
		current = first;
		while (current->next != NULL)
			current = current->next;
		current->next = first;
		(*s_sb)->head = first->next;
		first->next = NULL;
		if (type_bool == 1)
			ft_printf("rb\n");
	}
}

void	rr(t_stack **s_sa, t_stack **s_sb, int type_bool)
{
	if (*s_sa && *s_sb && ((*s_sa)->head
			&& (*s_sa)->head->next) && ((*s_sb)->head && (*s_sb)->head->next))
	{
		ra(s_sa, 0);
		rb(s_sb, 0);
		if (type_bool == 1)
			ft_printf("rr\n");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_method_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:27:47 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/25 17:19:50 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **s_sa, t_stack **s_sb)
{
	t_node	*tmp;

	if (!(*s_sb)->head)
		return ;
	tmp = (*s_sb)->head;
	(*s_sb)->head = tmp->next;
	tmp->next = (*s_sa)->head;
	(*s_sa)->head = tmp;
	ft_printf("pa\n");
}

void	pb(t_stack **s_sa, t_stack **s_sb)
{
	t_node	*tmp;

	if (!(*s_sa)->head)
		return ;
	tmp = (*s_sa)->head;
	(*s_sa)->head = tmp->next;
	tmp->next = (*s_sb)->head;
	(*s_sb)->head = tmp;
	ft_printf("pb\n");
}

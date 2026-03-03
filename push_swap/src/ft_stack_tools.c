/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:29:53 by aprivalo          #+#    #+#             */
/*   Updated: 2026/03/03 12:32:59 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_stack(t_stack *s, int value)
{
	t_node	*new;
	t_node	*tmp;

	new = malloc(sizeof(t_node));
	if (!new)
		error_exit(s);
	new->value = value;
	new->next = NULL;
	if (!s->head)
	{
		s->head = new;
		return ;
	}
	tmp = s->head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	free_stack(t_stack *s)
{
	t_node	*tmp;

	while (s->head)
	{
		tmp = s->head;
		s->head = s->head->next;
		free(tmp);
	}
}

int	stack_size(t_stack *s)
{
	t_node	*tmp;
	int		i;

	tmp = s->head;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	is_sorted(t_stack *s)
{
	t_node	*tmp;

	tmp = s->head;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	error_exit(t_stack *stack_a)
{
	if (stack_a)
		free_stack(stack_a);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

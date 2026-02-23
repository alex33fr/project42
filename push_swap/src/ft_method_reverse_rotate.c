/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_method_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:28:54 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/23 18:19:50 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra(t_stack **s_sa, int type_bool)
{
    t_node  *first;
    t_node  *current;
    t_node  *prev;

    prev = NULL;
    if (*s_sa && (*s_sa)->head && (*s_sa)->head->next)
    {
        first = (*s_sa)->head;
        current = first;
        while (current->next != NULL)
        {
            prev = current;
            current = current->next;
        }
        (*s_sa)->head = current;
        current->next = first;
        prev->next = NULL;
        if (type_bool == 1)
            ft_printf("rra\n");
    }
}

void    rrb(t_stack **s_sb, int type_bool)
{
    t_node  *first;
    t_node  *current;
    t_node  *prev;

    prev = NULL;
    if (*s_sb && (*s_sb)->head && (*s_sb)->head->next)
    {
        first = (*s_sb)->head;
        current = first;
        while (current->next != NULL)
        {
            prev = current;
            current = current->next;
        }
        (*s_sb)->head = current;
        current->next = first;
        prev->next = NULL;
        if (type_bool == 1)
            ft_printf("rrb\n");
    }
}

void    rrr(t_stack **s_sa, t_stack **s_sb, int type_bool)
{
        if (*s_sa && *s_sb && ((*s_sa)->head &&
        (*s_sa)->head->next) && ((*s_sb)->head && (*s_sb)->head->next))
    {
        rra(s_sa, 0);
        rrb(s_sb, 0);
        if (type_bool == 1)
            ft_printf("rrr\n");
    }
}
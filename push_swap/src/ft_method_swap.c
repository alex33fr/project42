/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_method_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:26:58 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/16 12:17:17 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_stack **sa)
{
    t_node  *target_sa;
    t_node  *next_sa;
    
    target_sa = NULL;
    next_sa = NULL;
    if (*sa && (*sa)->head && (*sa)->head->next)
    {
        next_sa = (*sa)->head->next;
        target_sa = next_sa->next;
        
        /*
        head = A
        next_sa = B
        target_sa = C
        */
        
        next_sa->next = (*sa)->head;
        (*sa)->head->next = target_sa;
        (*sa)->head = target_sa;
        ft_printf("sa\n");
    }
}

void    sb(t_stack **sb)
{
    t_node  *actual_sb;
    t_node  *next_sb;
    
    if (*sb && (*sb)->head && (*sb)->head->next)
    {
        actual_sb = next_sb->next;
        next_sb = (*sb)->head->next;
        next_sb->next = (*sb)->head;
        (*sb)->head->next = actual_sb;
        (*sb)->head = next_sb;
        ft_printf("sb\n");
    }
}

void    ss(t_stack **stack_a, t_stack **stack_b)
{
    
}
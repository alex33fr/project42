/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:46:18 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/23 18:18:57 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
typedef struct s_node
{
    int             cost_a;
    int             cost_b;
    int             value;
    int             index;
    struct s_node   *target;
    struct s_node   *next;
}   t_node;
typedef struct s_stack
{
    t_node  *head;
    int     size;
}   t_stack;
void    ft_push_swap(t_stack **stack_a, t_stack **stack_b);
void    sa(t_stack **stack_a, int type_bool);
void    sb(t_stack **stack_b, int type_bool);
void    ss(t_stack **stack_a, t_stack **stack_b, int type_bool);
void    pa(t_stack **stack_a, t_stack **stack_b);
void    pb(t_stack **stack_a, t_stack **stack_b);
void    ra(t_stack **stack_a, int type_bool);
void    rb(t_stack **stack_b, int type_bool);
void    rr(t_stack **stack_a, t_stack **stack_b, int type_bool);
void    rra(t_stack **stack_a, int type_bool);
void    rrb(t_stack **stack_b, int type_bool);
void    rrr(t_stack **stack_a, t_stack **stack_b, int type_bool);
#endif
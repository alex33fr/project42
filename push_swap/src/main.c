/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:30:38 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/15 16:33:39 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    if (ac >= 2)
    {
        ft_push_swap(av[1], NULL);
        return (1);
    }
    else
    {
        ft_printf("Error 1\n");
        return (1);
    }   
    return (0);
}
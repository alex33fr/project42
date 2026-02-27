/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_tools2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:19:19 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/26 14:14:55 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	**split_av(char *av, t_stack *stack_a)
{
	char	**tab;

	tab = ft_split(av, ' ');
	if (!tab)
		error_exit(stack_a);
	return (tab);
}

static void	atol_split(char **split, t_stack *stack_a)
{
	long	nbr;
	int		j;

	j = 0;
	while (split[j])
	{
		nbr = ft_atol(split[j]);
		if (nbr > 2147483647 || nbr < -2147483648)
		{
			free_split(split);
			error_exit(stack_a);
		}
		add_to_stack(stack_a, (int)nbr);
		j++;
	}
}

void	ft_split_stack(int ac, char **av, t_stack *stack_a)
{
	char	**tab_splited;
	int		i;

	i = 1;
	while (i < ac)
	{
		tab_splited = split_av(av[i], stack_a);
		atol_split(tab_splited, stack_a);
		free_split(tab_splited);
		i++;
	}
}

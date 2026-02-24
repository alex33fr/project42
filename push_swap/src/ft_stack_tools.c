/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:29:53 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/24 14:45:14 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  ft_split_stack(int ac, char **s)
{
    char    **tab;
    int i;

    i = 1;
    while (i < ac)
    {
        tab = ft_split(s[i], ' ');
        i++;
    }
    
    free(tab);
}

int	ft_check_av(char *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (!s[i])
			break ;
		res = 1;
		if (s[i] == '+' || s[i] == '-')
			i++;
		if (!ft_isdigit(s[i]))
			return (0);
		while (ft_isdigit(s[i]))
			i++;
		if (s[i] && s[i] != ' ')
			return (0);
	}
	return (res);
}
int	ft_check_input_av(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_check_av(av[i]))
			return (0);
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:30:38 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/27 11:01:52 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_digit(char *s)
{
	int	i;
	int	type_bool;

	i = 0;
	type_bool = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (!s[i])
			break ;
		type_bool = 1;
		if (s[i] == '+' || s[i] == '-')
			i++;
		if (ft_isdigit(s[i]) == 0)
			return (0);
		while (ft_isdigit(s[i]))
			i++;
		if (s[i] && s[i] != ' ')
			return (0);
	}
	return (type_bool);
}

int	ft_check_av(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_check_digit(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	check_dup(t_stack *stack_a)
{
	t_node	*current;
	t_node	*cmp;

	current = stack_a->head;
	while (current != NULL)
	{
		cmp = current->next;
		while (cmp != NULL)
		{
			if (current->value == cmp->value)
				error_exit(stack_a);
			cmp = cmp->next;
		}
		current = current->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac < 2)
		return (0);
	stack_a.head = NULL;
	stack_b.head = NULL;
	if (ft_check_av(ac, av) == 0)
		error_exit(NULL);
	ft_split_stack(ac, av, &stack_a);
	check_dup(&stack_a);
	if (!is_sorted(&stack_a))
		ft_push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

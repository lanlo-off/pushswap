/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:19:35 by llechert          #+#    #+#             */
/*   Updated: 2025/06/10 18:32:27 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack_string(char **tab, t_stack **stack, int nb_arg)
{
	int		i;
	long	nb;

	i = 0;
	while (i < nb_arg)
	{
		nb = ft_atol(tab[i]);
		if (nb < INT_MIN || nb > INT_MAX || !check_duplicates(stack, nb))
			return (0);
		if (!ft_add_new(nb, stack))
			return (0);
		i++;
	}
	if (!(*stack))
		return (0);
	indexation(stack, ft_stacksize(stack));
	return (1);
}

int	init_stack(int stack_size, char **av, t_stack **stack)
{
	int		i;
	long	nb;

	i = 0;
	while (i < stack_size)
	{
		nb = ft_atol(av[i + 1]);
		if (nb < INT_MIN || nb > INT_MAX || !check_duplicates(stack, nb))
			return (0);
		if (!ft_add_new(nb, stack))
			return (0);
		i++;
	}
	indexation(stack, stack_size);
	return (1);
}

/*
Index vont de 1 a stack_size
*/
void	indexation(t_stack **stack, int stack_size)
{
	t_stack	*tmp;
	t_stack	*highest;
	int		value;

	while (--stack_size >= 0)
	{
		tmp = *stack;
		value = INT_MIN;
		highest = NULL;
		while (tmp)
		{
			if (tmp->value == INT_MIN && tmp->index == 0)
				tmp->index = 1;
			if (tmp->value > value && tmp->index == 0)
			{
				value = tmp->value;
				highest = tmp;
			}
			tmp = tmp->next;
		}
		if (highest != NULL)
			highest->index = stack_size + 1;
	}
}

int	check_duplicates(t_stack **stack_a, long nb)
{
	t_stack	*tmp;

	if (!stack_a)
		return (1);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->value == (int)nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

long	ft_atol(char *str)
{
	long	nb;
	int		i;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i] || !(str[i] >= '0' && str[i] <= '9'))
		return ((long)INT_MAX + 1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	while (str[i] == ' ')
		i++;
	if (str[i])
		return ((long)INT_MAX + 1);
	return (nb * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:43:22 by llechert          #+#    #+#             */
/*   Updated: 2025/05/31 15:44:49 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_stack **stack_a, long nb)
{
	t_stack	*tmp;

	if (!stack_a)
		return (1);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->value == nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

long	ft_atol(char *str)
{
	long	nb;
	int		i;
	int		j;
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
	j = i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	if (j == i || str[i])//si aucun chiffre trouve ou si autre caractere derriere
		return ((long)INT_MAX + 1);//arg invalide car pas un nombre ==> fera sortir de la boucle dans valid arg
	return (nb * sign);
}

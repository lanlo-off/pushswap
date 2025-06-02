/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:19:35 by llechert          #+#    #+#             */
/*   Updated: 2025/06/02 10:35:57 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(int stack_size, char **av, t_stack **stack)
{
	int		i;
	long	nb;

	i = 0;
	while (i < stack_size)
	{
		nb = ft_atol(av[i + 1]);//atol strict qui ne fonctionne pas s'il y a d'autres caracteres apres le nombre
		if (nb < INT_MIN || nb > INT_MAX || !check_duplicates(stack, nb))
			return (0);//le free se fait depuis le main
		if (!ft_add_new(nb, stack))
			return (0);//si pb dans add new, free depuis main
		i++;
	}
	indexation(stack, stack_size);
	return (1);
}

void	indexation(t_stack **stack, int stack_size)
{
	t_stack	*tmp;
	t_stack	*highest;
	int		value;
	
	while (--stack_size >= 0)//l'indexation se passe du plus grand au plus petit donc on repete stack_size fois l'operation
	{
		tmp = *stack;
		value = INT_MIN;
		highest = NULL;
		while (tmp)
		{
			if (tmp->value == INT_MIN && tmp->index == 0)//si on rencontre INT MIN et qu'on l'a pas encore indexe on le met forcement a l'index 1 (necessaire car value est initialise a INT_MIN)
				tmp->index = 1;
			if (tmp->value > value && tmp->index == 0)//c'est ici qu'on exclut les elems deja indexes
			{
				value = tmp->value;
				highest = tmp;//on marque cet element comme etant le plus grand elem non indexe rencontre jusqu'a maintenant
			}
			tmp = tmp->next;//On avance d'un element si l'element precedent n'a pas une valeur > que celle en memoire ou s'il est deja indexe !
		}
		if (highest != NULL)//lorsqu'on a parcouru toute la liste on connait le plus grand chiffre
			highest->index = stack_size + 1;//on lui assigne donc l'index max de ce moment et on recommence pour l'index inferieur
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:19:35 by llechert          #+#    #+#             */
/*   Updated: 2025/05/31 16:51:47 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_new(long nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);//free dans le main ==> A checker
	new->value = nb;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	ft_add_new(long nb, t_stack **stack_a)
{
	t_stack	*new;
	t_stack	*tmp;

	new = ft_create_new(nb);
	if (!new)
		return (0);//free dans le main
	if (!*stack_a)
	{
		*stack_a = new;
		return (1);
	}
	tmp = *stack_a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;//une fois sur le dernier maillon deja existant, on peut ajouter le new en next
	new->prev = tmp;//en miroir, l'ancien dernier est le prev du new
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

int	valid_arg(int stack_size, char **av, t_stack **stack)
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

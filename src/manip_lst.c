/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:28:42 by llechert          #+#    #+#             */
/*   Updated: 2025/06/10 15:22:08 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_stack **lst)
{
	t_stack	*tmp;
	int		size;

	size = 0;
	tmp = *lst;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

t_stack	*ft_create_new(long nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);//free dans le main ==> A checker
	new->value = (int)nb;
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

t_stack	*get_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	get_highest_index_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		highest;
	int		position;
	int		i;

	highest = INT_MIN;
	tmp = *stack;
	i = 0;
	while (tmp)
	{
		if (tmp->value > highest)
		{
			highest = tmp->value;
			position = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (position);
}
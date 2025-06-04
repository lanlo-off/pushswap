/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:26:23 by llechert          #+#    #+#             */
/*   Updated: 2025/06/04 18:49:00 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rot_type(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;

	tmp = *stack_a;
	cheapest = cost_rarb(stack_a, stack_b, tmp->index);
	while (tmp)
	{
		cheapest = ft_min(cheapest, cost_rarb(stack_a, stack_b, tmp->index));
		cheapest = ft_min(cheapest, cost_rarrb(stack_a, stack_b, tmp->index));
		cheapest = ft_min(cheapest, cost_rrarb(stack_a, stack_b, tmp->index));
		cheapest = ft_min(cheapest, cost_rrarrb(stack_a, stack_b, tmp->index));
		tmp = tmp->next;
	}
	return (cheapest);
}

int	cost_rarb(t_stack **stack_a, t_stack **stack_b, int i)
{
	int		cost_a;
	int		cost_b;
	t_stack	*tmp;

	tmp = *stack_a;
	cost_a = 0;
	cost_b = 0;
	while (tmp->index != i)
	{
		cost_a++;
		tmp = tmp->next;
	}
	cost_b = cost_rb(stack_b, i);
	return (ft_max(cost_a, cost_b));//car pour le min on peut faire rr puis on fait que du plus grand
}

int	cost_rarrb(t_stack **stack_a, t_stack **stack_b, int i)
{
	int		cost_a;
	int		cost_b;
	t_stack	*tmp;

	tmp = *stack_a;
	cost_a = 0;
	cost_b = 0;
	while (tmp->index != i)
	{
		cost_a++;
		tmp = tmp->next;
	}
	cost_b = cost_rrb(stack_b, i);
	return (cost_a + cost_b);
}

int	cost_rrarb(t_stack **stack_a, t_stack **stack_b, int i)
{
	int		cost_a;
	int		cost_b;
	t_stack	*tmp;

	tmp = *stack_a;
	cost_a = 0;
	cost_b = 0;
	if (tmp->index != i)
		tmp = get_last(stack_a);
	while (tmp->index != i)
	{
		cost_a++;
		tmp = tmp->prev;
	}
	cost_b = cost_rb(stack_b, i);
	return (cost_a + cost_b);
}

int	cost_rrarrb(t_stack **stack_a, t_stack **stack_b, int i)
{
	int		cost_a;
	int		cost_b;
	t_stack	*tmp;
	
	tmp = *stack_a;
	cost_a = 0;
	cost_b = 0;
	if (tmp->index != i)//on ne part a reculon que si l'elem est pas deja premier
		tmp = get_last(stack_a);
	while (tmp->index != i)
	{
		cost_a++;
		tmp = tmp->prev;
	}
	cost_b = cost_rrb(stack_b, i);
	return (ft_max(cost_a, cost_b));//car pour le min on peut faire rrr puis on fait que du plus grand
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:26:23 by llechert          #+#    #+#             */
/*   Updated: 2025/06/10 18:29:46 by llechert         ###   ########.fr       */
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
		if (cheapest == 0)
			return (cheapest);
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
	return (ft_max(cost_a, cost_b));
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
		tmp = get_last(*stack_a);
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
	if (tmp->index != i)
		tmp = get_last(*stack_a);
	while (tmp->index != i)
	{
		cost_a++;
		tmp = tmp->prev;
	}
	cost_b = cost_rrb(stack_b, i);
	return (ft_max(cost_a, cost_b));
}

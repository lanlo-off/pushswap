/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:50:08 by llechert          #+#    #+#             */
/*   Updated: 2025/06/04 19:03:36 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_rb(t_stack **stack_b, int i)
{
	int		cost;
	t_stack	*tmp;

	cost = 0;
	tmp = *stack_b;
	if (i > tmp->index && i < get_last(stack_b)->index)
		return (cost);
	cost++;
	while (!(i > tmp->next->index && i < tmp->index))
	{
		cost++;
		tmp = tmp->next;
	}
	return (cost);
}

int	cost_rrb(t_stack **stack_b, int i)
{
	int		cost;
	t_stack	*tmp;

	cost = 0;
	tmp = get_last(stack_b);
	if (i > (*stack_b)->index && i < tmp->index)
		return (cost);
	cost++;
	while (!(i > tmp->index && i < tmp->prev->index))
	{
		cost++;
		tmp = tmp->prev;
	}
	return (cost);
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

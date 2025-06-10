/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_lst2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:28:35 by llechert          #+#    #+#             */
/*   Updated: 2025/06/10 11:53:34 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_stack **stack)
{
	t_stack	*tmp;
	int		min;

	min = INT_MAX;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

int	get_max_index(t_stack **stack)
{
	t_stack	*tmp;
	int		max;

	max = 0;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	count_r_sort(t_stack **stack)
{
	int		cost;
	t_stack	*tmp;
	
	cost = 0;
	tmp = *stack;
	while (tmp && tmp->index != get_max_index(stack))
	{
		cost++;
		tmp = tmp->next;
	}
	return (cost);
}

int	count_rr_sort(t_stack **stack)
{
	int		cost;
	t_stack	*tmp;
	
	cost = 0;
	tmp = get_last(*stack);
	while (tmp && tmp->index != get_max_index(stack))
	{
		cost++;
		tmp = tmp->prev;
	}
	return (cost);
}
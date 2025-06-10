/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:50:08 by llechert          #+#    #+#             */
/*   Updated: 2025/06/10 17:47:11 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_rb(t_stack **stack_b, int i)
{
	int		cost;
	t_stack	*tmp;

	cost = 1;
	if (!*stack_b)
		return (0);
	tmp = *stack_b;
	if (i > tmp->index && i < get_last(*stack_b)->index)
		return (0);
	if (i > get_max_index(stack_b) || i < get_min_index(stack_b))
		return (count_r_sort(stack_b));
	while (tmp->next && !(i > tmp->next->index && i < tmp->index))
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

	cost = 1;
	if (!*stack_b)
		return (0);
	tmp = get_last(*stack_b);
	if (i > (*stack_b)->index && i < tmp->index)
		return (0);
	if (i > get_max_index(stack_b) || i < get_min_index(stack_b))
		return (count_rr_sort(stack_b));
	while (tmp->next && !(i > tmp->index && i < tmp->prev->index))
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

int	count_arg(char **tab)
{
	int	count;

	count = 0;
	while (tab[count])
		count++;
	return (count);
}

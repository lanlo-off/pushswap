/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:00:20 by llechert          #+#    #+#             */
/*   Updated: 2025/06/10 18:36:03 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*tmp;

	if (!*stack_from)
		return ;
	tmp = (*stack_from)->next;
	if (tmp)
		tmp->prev = NULL;
	if (!*stack_to)
	{
		(*stack_from)->next = NULL;
		*stack_to = *stack_from;
	}
	else
	{
		(*stack_from)->next = (*stack_to);
		*stack_to = *stack_from;
		(*stack_to)->next->prev = *stack_to;
	}
	*stack_from = tmp;
}

void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}

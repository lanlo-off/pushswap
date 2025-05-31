/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:25:01 by llechert          #+#    #+#             */
/*   Updated: 2025/05/31 18:36:03 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack *stack)
{
	if (stack == NULL || stack->next == NULL)
		return ;
}

void	do_rra(t_stack **stack_a)
{
	rev_rotate(*stack_a);
	ft_printf("rra\n");
}

void	do_rrb(t_stack **stack_b)
{
	rev_rotate(*stack_b);
	ft_printf("rrb\n");
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(*stack_a);
	rev_rotate(*stack_b);
	ft_printf("rrr\n");
}
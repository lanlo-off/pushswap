/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:20:41 by llechert          #+#    #+#             */
/*   Updated: 2025/05/31 18:36:10 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	if (stack == NULL || stack->next == NULL)
		return ;
}

void	do_ra(t_stack **stack_a)
{
	rotate(*stack_a);
	ft_printf("ra\n");
}

void	do_rb(t_stack **stack_b)
{
	rotate(*stack_b);
	ft_printf("rb\n");
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(*stack_a);
	rotate(*stack_b);
	ft_printf("rr\n");
}
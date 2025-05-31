/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:49:23 by llechert          #+#    #+#             */
/*   Updated: 2025/05/31 18:34:50 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;
	
	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;//on stocke la valeur de l'ancien premier elem
	stack->value = stack->next->value;//l'ancien premier element prend la valeur du 2eme element
	stack->next->value = tmp;//et l'ancien deuxieme prend la valeur de l'ancien premier
	tmp = stack->index;//on stocke la valeur de l'ancien premier elem
	stack->index = stack->next->index;//l'ancien premier element prend la valeur du 2eme element
	stack->next->index = tmp;//et l'ancien deuxieme prend la valeur de l'ancien premier
}

void	do_sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_printf("sa\n");
}

void	do_sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_printf("sb\n");
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_printf("ss\n");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:49:23 by llechert          #+#    #+#             */
/*   Updated: 2025/06/01 18:42:02 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)//on manipule pas **stack car on ne change pas la tete de la pile mais on intervertit les valeurs (different de rotate)
{
	int	tmp;
	
	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;//on stocke la valeur de l'ancien premier elem
	stack->value = stack->next->value;//l'ancien premier element prend la valeur du 2eme element
	stack->next->value = tmp;//et l'ancien deuxieme prend la valeur de l'ancien premier
	tmp = stack->index;//on stocke l'index de l'ancien premier elem
	stack->index = stack->next->index;//l'ancien premier element prend l'index du 2eme element
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
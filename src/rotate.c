/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:20:41 by llechert          #+#    #+#             */
/*   Updated: 2025/06/06 14:57:33 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	
	if (!*stack)
		return ;
	tmp = *stack;//tmp pointe sur le premier element
	*stack = (*stack)->next;//decalage de la tete de liste
	(*stack)->prev = NULL;//tete de liste doinc n'a pas de prev
	last = get_last(*stack);//on va chercher le dernier elem
	tmp->next = NULL;//on place le premier elem en dernier
	tmp->prev = last;
	last->next = tmp;//on fait le raccordement dans les 2 sens (prev et next)
}

void	do_ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	do_rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}

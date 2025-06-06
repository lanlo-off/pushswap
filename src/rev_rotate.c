/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:25:01 by llechert          #+#    #+#             */
/*   Updated: 2025/06/06 14:57:22 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*tmp;
	
	if (!*stack)
		return ;
	last = get_last(*stack);//on recupere le dernier
	tmp = last->prev;
	tmp->next = NULL;//l'avant dernier devient le dernier
	last->prev = NULL;//le dernier va devenir le premier
	last->next = *stack;//on connecte l'ancien premier avec le nouveau premier
	(*stack)->prev = last;//l'ancien premier est maintenant 2eme
	*stack = last;//on fait pointer le debut de liste sur le nouveau premier	
}

void	do_rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_printf("rra\n");
}

void	do_rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_printf("rrb\n");
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_printf("rrr\n");
}

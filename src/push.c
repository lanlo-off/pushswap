/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:00:20 by llechert          #+#    #+#             */
/*   Updated: 2025/06/06 15:20:50 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*tmp;
	
	if (!*stack_from)//pas de deplacement si pas d'elem a push
		return ;
	tmp = (*stack_from)->next;//on marque celui qui va devenir premier de la stack from
	if (tmp)
		tmp->prev = NULL;//on dereference le prev uniquement si l'element tmp existait
	if (!*stack_to)//si pas d'elem dans to, on veut juste l'envoyer et rien faire d'autre dans to
	{
		(*stack_from)->next = NULL;//Il devient le premier elem mais surtout le seul donc pas de next
		*stack_to = *stack_from;//on fait pointer la tete de liste de to vers l'ancien premier element de from
	}
	else//sinon on l'envoie bien mais on fait aussi le raccordement
	{
		(*stack_from)->next = (*stack_to);//connecte l'ancien premier elem de from a l'ancien premier elem de to (pas besoin de modifier son prev qui etait deja null car premier)
		*stack_to = *stack_from;
		(*stack_to)->next->prev = *stack_to;//on raccorde le previous du deuxieme elem au nouveau premier
	}
	*stack_from = tmp;//on fait pointer la stack from vers tmp = le nouveau premier elem (y compris null)
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

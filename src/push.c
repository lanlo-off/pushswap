/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:00:20 by llechert          #+#    #+#             */
/*   Updated: 2025/06/01 17:25:33 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack_from, t_stack *stack_to)
{
	if (stack_from == NULL)//pas de deplacement
		return ;
	if (stack_to == NULL)//devient le premier elem
	{
		stack_to = stack_from;
		stack_to->next = NULL;//Comme c'est le seul elem pas next ni prev
		stack_to->prev = NULL;
		stack_from = stack_from->next;//fonctionne meme si pas d'elem suivant
	}
	else//a revoir
	{
		stack_to->prev = stack_from;
		stack_to->next = stack_from->next;
		if (stack_from->next != NULL)
			stack_from->next->prev = stack_to;
		stack_from->next = stack_to;
		stack_from = stack_from->next;
	}
}
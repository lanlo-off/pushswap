/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:26:40 by llechert          #+#    #+#             */
/*   Updated: 2025/06/06 14:27:00 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_rarb(t_stack **stack_a, t_stack **stack_b, int i)
{
	while ((*stack_a)->index != i
		&& !(i > (*stack_b)->index && i < get_last(*stack_b)->index))
		do_rr(stack_a, stack_b);
	while ((*stack_a)->index != i)//en ecrivant comme ca plutot que par un tmp, on regarde le premier de la liste (qui change apres avoir fait ra donc pas de boucle inf)
		do_ra(stack_a);
	while (!(i > (*stack_b)->index && i < get_last(*stack_b)->index))
		do_rb(stack_b);
	return (-1);
}

int	choose_rarrb(t_stack **stack_a, t_stack **stack_b, int i)
{
	while ((*stack_a)->index != i)
		do_ra(stack_a);
	while (!(i > (*stack_b)->index && i < get_last(*stack_b)->index))
		do_rrb(stack_b);
	return (-1);
}

int	choose_rrarb(t_stack **stack_a, t_stack **stack_b, int i)
{
	while ((*stack_a)->index != i)
		do_rra(stack_a);
	while (!(i > (*stack_b)->index && i < get_last(*stack_b)->index))
		do_rb(stack_b);
	return (-1);
}

int	choose_rrarrb(t_stack **stack_a, t_stack **stack_b, int i)
{
	while ((*stack_a)->index != i
		&& !(i > (*stack_b)->index && i < get_last(*stack_b)->index))
		do_rrr(stack_a, stack_b);
	while ((*stack_a)->index != i)
		do_rra(stack_a);
	while (!(i > (*stack_b)->index && i < get_last(*stack_b)->index))
		do_rrb(stack_b);
	return (-1);
}

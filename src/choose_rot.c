/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:26:40 by llechert          #+#    #+#             */
/*   Updated: 2025/06/10 17:15:25 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_rarb(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (i > get_max_index(stack_b) || i < get_min_index(stack_b))
	{
		while ((*stack_a)->index != i && !is_rev_sorted(stack_b))
			do_rr(stack_a, stack_b);
		while ((*stack_a)->index != i)//en ecrivant comme ca plutot que par un tmp, on regarde le premier de la liste (qui change apres avoir fait ra donc pas de boucle inf)
			do_ra(stack_a);
		while (!is_rev_sorted(stack_b))
			do_rb(stack_b);
	}
	else 
	{
		while ((*stack_a)->index != i
			&& !(i > (*stack_b)->index && i < get_last(*stack_b)->index))
			do_rr(stack_a, stack_b);
		while ((*stack_a)->index != i)
			do_ra(stack_a);
		while (!(i > (*stack_b)->index && i < get_last(*stack_b)->index))
			do_rb(stack_b);
	}
	do_pb(stack_a, stack_b);
	return (-1);
}

int	choose_rarrb(t_stack **stack_a, t_stack **stack_b, int i)
{
	while ((*stack_a)->index != i)
		do_ra(stack_a);
	if (i > get_max_index(stack_b) || i < get_min_index(stack_b))
	{
		while (!is_rev_sorted(stack_b))
			do_rrb(stack_b);
	}
	else
	{
		while (!(i > (*stack_b)->index && i < get_last(*stack_b)->index))
		do_rrb(stack_b);
	}
	do_pb(stack_a, stack_b);
	return (-1);
}

int	choose_rrarb(t_stack **stack_a, t_stack **stack_b, int i)
{
	while ((*stack_a)->index != i)
		do_rra(stack_a);
	if (i > get_max_index(stack_b) || i < get_min_index(stack_b))
	{
		while (!is_rev_sorted(stack_b))
			do_rb(stack_b);
	}
	else
	{
		while (!(i > (*stack_b)->index && i < get_last(*stack_b)->index))
		do_rb(stack_b);
	}
	do_pb(stack_a, stack_b);
	return (-1);
}

int	choose_rrarrb(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (i > get_max_index(stack_b) || i < get_min_index(stack_b))
	{
		while ((*stack_a)->index != i && !is_rev_sorted(stack_b))
			do_rrr(stack_a, stack_b);
		while ((*stack_a)->index != i)
			do_rra(stack_a);
		while (!is_rev_sorted(stack_b))
			do_rrb(stack_b);
	}
	else
	{
		while ((*stack_a)->index != i
			&& !(i > (*stack_b)->index && i < get_last(*stack_b)->index))
			do_rrr(stack_a, stack_b);
		while ((*stack_a)->index != i)
			do_rra(stack_a);
		while (!(i > (*stack_b)->index && i < get_last(*stack_b)->index))
			do_rrb(stack_b);
	}
	do_pb(stack_a, stack_b);
	return (-1);
}

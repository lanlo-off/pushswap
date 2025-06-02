/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:42:02 by llechert          #+#    #+#             */
/*   Updated: 2025/06/02 11:36:43 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack **stack_a)
{
	int	highest;
	
	highest = get_higher_index_pos(stack_a);
	if (highest == 1)
		do_ra(stack_a);
	if (highest == 2)
		do_rra(stack_a);
	if (!is_sorted(stack_a))
		do_sa(stack_a);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:42:02 by llechert          #+#    #+#             */
/*   Updated: 2025/06/10 18:38:48 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack **stack_a)
{
	int	highest;
	int	size_a;

	size_a = ft_stacksize(stack_a);
	if (size_a != 3)
		return ;
	highest = get_highest_index_pos(stack_a);
	if (highest == 0)
		do_ra(stack_a);
	if (highest == 1)
		do_rra(stack_a);
	if (!is_sorted(stack_a))
		do_sa(stack_a);
}

void	sort(t_stack **stack_a)
{
	t_stack	**stack_b;

	stack_b = malloc(sizeof(t_stack *));
	if (!stack_b)
		return ;
	*stack_b = NULL;
	if (ft_stacksize(stack_a) > 3 && !is_sorted(stack_a))
		do_pb(stack_a, stack_b);
	if (ft_stacksize(stack_a) > 3 && !is_sorted(stack_a))
		do_pb(stack_a, stack_b);
	rot_and_sort(stack_a, stack_b);
	tiny_sort(stack_a);
	pushback(stack_a, stack_b);
	free(stack_b);
}

void	rot_and_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		cheapest;
	t_stack	*tmp;

	while (ft_stacksize(stack_a) > 3 && !is_sorted(stack_a))
	{
		tmp = *stack_a;
		cheapest = rot_type(stack_a, stack_b);
		while (cheapest >= 0)
		{
			if (cheapest == cost_rarb(stack_a, stack_b, tmp->index))
				cheapest = choose_rarb(stack_a, stack_b, tmp->index);
			else if (cheapest == cost_rarrb(stack_a, stack_b, tmp->index))
				cheapest = choose_rarrb(stack_a, stack_b, tmp->index);
			else if (cheapest == cost_rrarb(stack_a, stack_b, tmp->index))
				cheapest = choose_rrarb(stack_a, stack_b, tmp->index);
			else if (cheapest == cost_rrarrb(stack_a, stack_b, tmp->index))
				cheapest = choose_rrarrb(stack_a, stack_b, tmp->index);
			else
				tmp = tmp->next;
		}
	}
}

void	pushback(t_stack **stack_a, t_stack **stack_b)
{
	easy_rev_sort(stack_b);
	while (*stack_b)
	{
		if ((*stack_a)->index > get_last(*stack_a)->index
			&& (*stack_b)->index < get_last(*stack_a)->index)
			do_rra(stack_a);
		else if ((*stack_b)->index < (*stack_a)->index
			|| (*stack_b)->index > get_last(*stack_a)->index)
			do_pa(stack_a, stack_b);
		else if ((*stack_a)->index < get_last(*stack_a)->index
			&& (*stack_b)->index < (*stack_a)->index)
			do_rra(stack_a);
		else
			do_rra(stack_a);
	}
	if (get_highest_index_pos(stack_a) > ft_stacksize(stack_a) / 2)
	{
		while ((*stack_a)->index != 1)
			do_rra(stack_a);
	}
	else
	{
		while ((*stack_a)->index != 1)
			do_ra(stack_a);
	}
}

/*on positionne le plus grand index au top 
selon s'il est au debut ou a la fin de la stack_b*/
void	easy_rev_sort(t_stack **stack)
{
	int	highest_index_pos;
	int	stack_size;
	int	nb_rot;

	stack_size = ft_stacksize(stack);
	highest_index_pos = get_highest_index_pos(stack);
	if (highest_index_pos > stack_size / 2)
	{
		nb_rot = stack_size - highest_index_pos;
		while (nb_rot)
		{
			do_rrb(stack);
			nb_rot--;
		}
	}
	else
	{
		nb_rot = highest_index_pos;
		while (nb_rot)
		{
			do_rb(stack);
			nb_rot--;
		}
	}
}

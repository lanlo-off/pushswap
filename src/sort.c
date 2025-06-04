/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:42:02 by llechert          #+#    #+#             */
/*   Updated: 2025/06/04 17:43:34 by llechert         ###   ########.fr       */
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
	highest = get_higher_index_pos(stack_a);
	if (highest == 0)
		do_ra(stack_a);
	if (highest == 1)
		do_rra(stack_a);
	if (!is_sorted(stack_a))
		do_sa(stack_a);
}

void	sort(t_stack **stack_a, int size_a)
{
	t_stack	**stack_b;
	int		i;

	i = 0;
	stack_b = malloc(sizeof(t_stack *));
	if (!stack_b)
		return ;
	rot_and_sort(stack_a, stack_b);
	biggest_first(stack_b);//la on fait tourner b jusaqu'a avoir le plus grand elem de B devant
	tiny_sort(stack_a);//on trie les 3 valeurs restantes si necessaire
	pushback(stack_a, stack_b);//on renvoie tout ce qui est dans b dans l'ordre du plus grand au plus petit en faisant attention
	//car le plus grand de la stack a peut-etre plus grand ou plus petit que le plus grand de la stack b.
	free(stack_b);
}

void	rot_and_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		cheapest;
	int		i;
	t_stack	*tmp;

	i = 0;
	while (i < size_a - 3 && !is_sorted(stack_a))//ajout is_sorted car si c'est le cas alors on peut pushback b sans allerjusaqu'a 3 elems dans A
	{
		tmp = *stack_a;
		cheapest = rot_type(stack_a, stack_b);//rarb ou rarrb ou rrarb ou rrarrb (on va utiliser ici les fonctions avec lesquelles on va comparer cheapest just en dessous)
		while (tmp)
		{
			if (cheapest == cost_rarb(stack_a, stack_b, tmp->index))
				choose_rarb(stack_a, stack_b, tmp->index);
			else if (cheapest == cost_rarrb(stack_a, stack_b, tmp->index))
				choose_rarrb(stack_a, stack_b, tmp->index);
			else if (cheapest == cost_rrarb(stack_a, stack_b, tmp->index))
				choose_rrarb(stack_a, stack_b, tmp->index);
			else if (cheapest == cost_rrarrb(stack_a, stack_b, tmp->index))
				choose_rrarrb(stack_a, stack_b, tmp->index);
			else
				tmp = tmp->next;
		}
	}
}
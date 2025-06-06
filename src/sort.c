/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:42:02 by llechert          #+#    #+#             */
/*   Updated: 2025/06/06 16:03:58 by llechert         ###   ########.fr       */
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
	if (ft_stacksize(stack_a) > 3 && !is_sorted(stack_a))
		do_pb(stack_a, stack_b);
	if (ft_stacksize(stack_a) > 3 && !is_sorted(stack_a))
		do_pb(stack_a, stack_b);
	rot_and_sort(stack_a, stack_b);
	tiny_sort(stack_a);//on trie les 3 valeurs restantes si necessaire
	pushback(stack_a, stack_b);//on renvoie tout ce qui est dans b dans l'ordre du plus grand au plus petit en faisant attention
	//car le plus grand de la stack a peut-etre plus grand ou plus petit que le plus grand de la stack b.
	free(stack_b);
}


void	rot_and_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		cheapest;
	t_stack	*tmp;

	while (ft_stacksize(stack_a) > 3 && !is_sorted(stack_a))//ajout is_sorted car si c'est le cas alors on peut pushback b sans allerjusaqu'a 3 elems dans A
	{
		tmp = *stack_a;
		cheapest = rot_type(stack_a, stack_b);//rarb ou rarrb ou rrarb ou rrarrb (on va utiliser ici les fonctions avec lesquelles on va comparer cheapest just en dessous)
		while (cheapest >= 0)//on parcourt tous les elements jusqu'a retrouver notre cout minimal sur la rotation ==> 
		//si on a le meme cout pour 2 elems c'est pas genant car on les traite 
		//dans le meme ordre pour l'execution que pour les couts et si les couts 
		//sont egaux pour 2 elems on garde le premier qu'on a vu donc la boucle 
		//s'arrete et ne s'applique pas pour l'autre element
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
	easy_rev_sort(stack_b);//uniquement des rb et rrb pour mettre le plus grand en haut de la pile
	while (*stack_b)
	{
		if ((*stack_a)->index > get_last(*stack_a)->index
			&& (*stack_b)->index < get_last(*stack_a)->index)
			do_rra(stack_a);
		else if((*stack_b)->index < (*stack_a)->index
			|| (*stack_b)->index > get_last(*stack_a)->index)
			do_pa(stack_a, stack_b);
		else if ((*stack_a)->index < get_last(*stack_a)->index
			&& (*stack_b)->index < (*stack_a)->index)
			do_rra(stack_a);
		else
			do_rra(stack_a);
	}
	while ((*stack_a)->index != 1)
		do_rra(stack_a);
}

/*on positionne le plus grand index au top selon s'il est au debut ou a la fin de la stack_b*/
void	easy_rev_sort(t_stack **stack)
{
	int	highest_index_pos;

	highest_index_pos = get_highest_index_pos(stack);//si a la fin de la stack -> rrb
	if (highest_index_pos > ft_stacksize(stack) / 2)
	{
		while (highest_index_pos)
		{
			do_rrb(stack);
			highest_index_pos--;
		}
	}
	else//si dans la premiere partie, on fait du rb plutot que rrb
	{
		while (highest_index_pos)
		{
			do_rb(stack);
			highest_index_pos--;
		}
	}
}

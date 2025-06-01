/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:57:06 by llechert          #+#    #+#             */
/*   Updated: 2025/06/01 17:00:38 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	**stack_a;

	if (ac < 2)
		return (0);
	stack_a = malloc(sizeof(t_stack *));
	if (!stack_a)
		return (1);
	*stack_a = NULL;
	if (!valid_arg(ac - 1, av, stack_a))
	{
		free_list(stack_a);
		ft_printf("Error\n");
		return (1);
	}
	ft_test_init(stack_a);//a supprimer avec la fonction en dessous
	ft_pushswap(stack_a, ac - 1);
	free_list(stack_a);
	return (0);
}

void	ft_pushswap(t_stack **stack_a, int stack_size)
{
	if (stack_size == 1)
		return ;
	else if (stack_size == 2 && !is_sorted(stack_a))
		do_sa(stack_a);
	// else if (stack_size == 3 && !is_sorted(stack_a))
	// 	tiny_sort(stack_a);
	// else if (stack_size > 3 && !is_sorted(stack_a))
	// 	sort(stack_a);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*tmp;
	int		previous;
	
	if (!*stack)
		return (1);
	tmp = *stack;
	previous = tmp->value;
	while (tmp)
	{
		if (tmp->value < previous)
			return (0);
		previous = tmp->value;
		tmp = tmp->next;
	}
	return (1);
}

void	ft_test_init(t_stack **stack)//a balancer apres tests
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		ft_printf("valeur : %d || ", tmp->value);
		ft_printf("index : %d\n", tmp->index);
		tmp = tmp->next;
	}
}
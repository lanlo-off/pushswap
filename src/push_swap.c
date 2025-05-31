/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:57:06 by llechert          #+#    #+#             */
/*   Updated: 2025/05/31 15:40:22 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	**stack_a;
	t_stack	*tmp = NULL;//a supprimer apres test

	if (ac < 2)
		return (1);
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
	tmp = *stack_a;
	while (tmp)//a supprimer apres test
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	// ft_pushswap(stack_a);
	free_list(stack_a);
	return (0);
}

void	free_list(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	free(stack);
}
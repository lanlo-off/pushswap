/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:57:06 by llechert          #+#    #+#             */
/*   Updated: 2025/06/10 20:48:20 by llechert         ###   ########.fr       */
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
		return (0);
	*stack_a = NULL;
	if (ac == 2)
	{
		if (!split_arg(av[1], stack_a))
			return (0);
	}
	else if (!init_stack(ac - 1, av, stack_a))
	{
		error_exit(stack_a);
		return (0);
	}
	ft_pushswap(stack_a, ft_stacksize(stack_a));
	return (0);
}

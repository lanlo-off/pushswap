/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:57:06 by llechert          #+#    #+#             */
/*   Updated: 2025/06/10 13:04:51 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	**stack_a;
	char 	**tmp;

	if (ac < 2)
		return (0);
	stack_a = malloc(sizeof(t_stack *));
	if (!stack_a)
		return (1);
	*stack_a = NULL;
	if (ac == 2)
	{
		tmp = ft_split(av[1], " ");
		if (!init_stack(count_args(tmp), tmp, stack_a))
			error_exit(stack_a);
		free_tab(tmp);
	}
	else if(!init_stack(ac - 1, av, stack_a))
		error_exit(stack_a);
	ft_test_init(stack_a);//a supprimer avec la fonction en dessous
	ft_pushswap(stack_a, ft_stacksize(stack_a));//pas sur que la protection fonctionne dans le cas ou on a fait error exit
	return (0);
}

void	ft_pushswap(t_stack **stack_a, int stack_size)
{
	if (!(*stack_a))
		return ;
	if( stack_size <= 1)
	{
		free_list(stack_a);
		return ;
	}
	else if (stack_size == 2 && !is_sorted(stack_a))
		do_sa(stack_a);
	else if (stack_size == 3 && !is_sorted(stack_a))//condition !is_sorted inutile car mon tiny sort gere si c'est deja trie
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(stack_a))
	{
		sort(stack_a);
		if (!is_sorted(stack_a))//inutile si algo de qualite
			ft_printf("Erreur de tri !\n");
	}
	
}

int	is_sorted(t_stack **stack)
{
	t_stack	*tmp;
	int		previous;
	
	if (!(*stack))
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

int	is_rev_sorted(t_stack **stack)
{
	t_stack	*tmp;
	int		previous;
	
	if (!(*stack))
		return (1);
	tmp = *stack;
	previous = tmp->value;
	while (tmp)
	{
		if (previous < tmp->value)
			return (0);
		previous = tmp->value;
		tmp = tmp->next;
	}
	return (1);
}

void	ft_test_init(t_stack **stack)//a virer apres tests
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

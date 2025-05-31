/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:27:46 by llechert          #+#    #+#             */
/*   Updated: 2025/05/31 18:35:10 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include "ft_printf.h"
# include "libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

/*ft_free.c*/
void	free_list(t_stack **stack);

/*push_swap.c*/
void	ft_test_init(t_stack **stack);
int		is_sorted(t_stack **stack);
void	ft_pushswap(t_stack **stack_a, int stack_size);

/* init_stack.c */
void	indexation(t_stack **stack, int stack_size);
t_stack	*ft_create_new(long nb);
int		ft_add_new(long nb, t_stack **stack_a);
int		valid_arg(int stack_size, char **av, t_stack **stack);

/*init_utils.c*/
int		check_duplicates(t_stack **stack_a, long nb);
long	ft_atol(char *str);

/* swap.c*/
void	swap(t_stack *stack);
void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);

/* rotate.c*/
void	rotate(t_stack *stack);
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);

/*rev_rotate.c*/
void	rev_rotate(t_stack *stack);
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);

#endif
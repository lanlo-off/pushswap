/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:27:46 by llechert          #+#    #+#             */
/*   Updated: 2025/06/04 17:51:16 by llechert         ###   ########.fr       */
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

/*choose_rot.c*/
void	choose_rarb(t_stack **stack_a, t_stack **stack_b, int i);
void	choose_rarrb(t_stack **stack_a, t_stack **stack_b, int i);
void	choose_rrarb(t_stack **stack_a, t_stack **stack_b, int i);
void	choose_rrarrb(t_stack **stack_a, t_stack **stack_b, int i);

/*cost_rot.c*/
int	rot_type(t_stack **stack_a, t_stack **stack_b);
int		cost_rarb(t_stack **stack_a, t_stack **stack_b, int i);
int		cost_rarrb(t_stack **stack_a, t_stack **stack_b, int i);
int		cost_rrarb(t_stack **stack_a, t_stack **stack_b, int i);
int		cost_rrarrb(t_stack **stack_a, t_stack **stack_b, int i);

/*ft_free.c*/
void	free_list(t_stack **stack);

/* init_stack.c */
void	indexation(t_stack **stack, int stack_size);
int		init_stack(int stack_size, char **av, t_stack **stack);
int		check_duplicates(t_stack **stack_a, long nb);
long	ft_atol(char *str);

/*main.c*/
void	ft_test_init(t_stack **stack);
int		is_sorted(t_stack **stack);
void	ft_pushswap(t_stack **stack_a, int stack_size);

/*manip_lst.c*/
int		ft_stacksize(t_stack **lst);
int		get_highest_index_pos(t_stack **stack);
t_stack	*ft_create_new(long nb); 
int		ft_add_new(long nb, t_stack **stack_a);
t_stack	*get_last(t_stack *stack);

/*push.c*/
void	do_pb(t_stack **stack_a, t_stack **stack_b);
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack_from, t_stack **stack_to);

/*rev_rotate.c*/
void	rev_rotate(t_stack **stack);
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);

/* rotate.c*/
void	rotate(t_stack **stack);
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);

/*sort.c*/
void	rot_and_sort(t_stack **stack_a, t_stack **stack_b);
void	sort(t_stack **stack_a, int size_a);
void	tiny_sort(t_stack **stack_a);

/* swap.c*/
void	swap(t_stack *stack);
void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);

/*utils*/
int	ft_min(int a, int b);

#endif
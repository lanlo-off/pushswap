/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:27:46 by llechert          #+#    #+#             */
/*   Updated: 2025/06/10 16:32:14 by llechert         ###   ########.fr       */
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
int		choose_rarb(t_stack **stack_a, t_stack **stack_b, int i);
int		choose_rarrb(t_stack **stack_a, t_stack **stack_b, int i);
int		choose_rrarb(t_stack **stack_a, t_stack **stack_b, int i);
int		choose_rrarrb(t_stack **stack_a, t_stack **stack_b, int i);

/*cost_rot.c*/
int		rot_type(t_stack **stack_a, t_stack **stack_b);
int		cost_rarb(t_stack **stack_a, t_stack **stack_b, int i);
int		cost_rarrb(t_stack **stack_a, t_stack **stack_b, int i);
int		cost_rrarb(t_stack **stack_a, t_stack **stack_b, int i);
int		cost_rrarrb(t_stack **stack_a, t_stack **stack_b, int i);

/*cost_utils.c*/
int		cost_rb(t_stack **stack_b, int i);
int		cost_rrb(t_stack **stack_b, int i);
int		ft_min(int a, int b);
int		ft_max(int a, int b);

/*free_and_error.c*/
void	free_list(t_stack **stack);
void	free_tab(char **tab);
void	error_exit(t_stack **stack);

/* init_stack.c */
void	indexation(t_stack **stack, int stack_size);
int		init_stack_string(char **tab, t_stack **stack, int nb_arg);
int		init_stack(int stack_size, char **av, t_stack **stack);
int		check_duplicates(t_stack **stack_a, long nb);
long	ft_atol(char *str);

/*main.c*/
void	ft_test_init(t_stack **stack);
int		is_sorted(t_stack **stack);
int		is_rev_sorted(t_stack **stack);
void	ft_pushswap(t_stack **stack_a, int stack_size);
int		split_arg(char *av, t_stack **stack_a);
void print_debug(t_stack *stack, char *name);//a supprimer ensuite
int	count_arg(char **tab);

/*manip_lst.c*/
int		ft_stacksize(t_stack **lst);
t_stack	*ft_create_new(long nb);
int		ft_add_new(long nb, t_stack **stack_a);
t_stack	*get_last(t_stack *stack);
int		get_highest_index_pos(t_stack **stack);

/*manip_lst2.c*/
int		get_min_index(t_stack **stack);
int		get_max_index(t_stack **stack);
int		count_r_sort(t_stack **stack);
int		count_rr_sort(t_stack **stack);

/*push.c*/
void	push(t_stack **stack_from, t_stack **stack_to);
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);

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
void	tiny_sort(t_stack **stack_a);
void	sort(t_stack **stack_a);
void	rot_and_sort(t_stack **stack_a, t_stack **stack_b);
void	pushback(t_stack **stack_a, t_stack **stack_b);
void	easy_rev_sort(t_stack **stack);

/* swap.c*/
void	swap(t_stack *stack);
void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);

#endif
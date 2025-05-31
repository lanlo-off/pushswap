/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:27:46 by llechert          #+#    #+#             */
/*   Updated: 2025/05/31 15:53:37 by llechert         ###   ########.fr       */
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

/*push_swap.c*/
void	free_list(t_stack **stack);

/* init_stack.c */
void	indexation(t_stack **stack, int stack_size);
t_stack	*ft_create_new(long nb);
int	ft_add_new(long nb, t_stack **stack_a);
int	valid_arg(int stack_size, char **av, t_stack **stack);

/*init_utils.c*/
int	check_duplicates(t_stack **stack_a, long nb);
long	ft_atol(char *str);

#endif
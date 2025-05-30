/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:57:06 by llechert          #+#    #+#             */
/*   Updated: 2025/05/30 15:59:09 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft_git/libft.h"

int	main(int ac, char **av)
{
	int	*tab;

	if (ac < 2)
		return (1);
	tab = ft_calloc(ac - 1, sizeof(int));
	if (!tab)
		return (1);
	if (!valid_arg(ac - 1, av, tab))
	{
		free(tab);
		write(2, "Error\n", 6);
		return (1);
	}
	int	i = 0;
	while (i < ac - 1)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	// ft_pushswap(tab);
	free(tab);
	return (0);
}

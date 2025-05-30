/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:19:35 by llechert          #+#    #+#             */
/*   Updated: 2025/05/30 16:35:54 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft_git/libft.h"

int	valid_arg(int nb_args, char **av, int *tab)
{
	int		i;
	int		j;
	long	nb;

	i = 0;
	while (i < nb_args)
	{
		nb = ft_atol(av[i + 1]);//atol strict ne fonctionne pas s'il y a d'autres caracteres apres le nombre
		if (nb < INT_MIN || nb > INT_MAX)
			return (0);
		j = 0;
		while (j < i)//check les doublons
		{
			if (tab[j] == (int)nb)
				return (0);
			j++;
		}
		tab[i] = (int)nb;
		i++;
	}
	return(1);
}

long	ft_atol(char *str)
{
	long	nb;
	int		i;
	int		j;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	j = i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	if (j == i || str[i])//si aucun chiffre trouve ou si autre caractere derriere
		return ((long)INT_MAX + 1);//arg invalide car pas un nombre ==> fera sortir de la boucle dans valid arg
	return (nb * sign);
}

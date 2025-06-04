/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llechert <llechert@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:26:23 by llechert          #+#    #+#             */
/*   Updated: 2025/06/04 17:52:35 by llechert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	rot_type(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;

	tmp = *stack_a;
	cheapest = cost_rarb(stack_a, stack_b, tmp->index);
	while (tmp)
	{
		cheapest = ft_min(cheapest, cost_rarb(stack_a, stack_b, tmp->index));
		cheapest = ft_min(cheapest, cost_rarrb(stack_a, stack_b, tmp->index));
		cheapest = ft_min(cheapest, cost_rrarb(stack_a, stack_b, tmp->index));
		cheapest = ft_min(cheapest, cost_rrarrb(stack_a, stack_b, tmp->index));
	}
	return (cheapest);
}

int	cost_rarb(t_stack **stack_a, t_stack **stack_b, int i)
{
	
}

int	cost_rarrb(t_stack **stack_a, t_stack **stack_b, int i)
{
	
}

int	cost_rrarb(t_stack **stack_a, t_stack **stack_b, int i)
{
	
}

int	cost_rrarrb(t_stack **stack_a, t_stack **stack_b, int i)
{
	
}
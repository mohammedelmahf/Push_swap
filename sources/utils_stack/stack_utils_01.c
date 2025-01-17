/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:24:29 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/17 11:42:24 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_stack **a)
{
	if (stack_size(*a) >= 2)
	{
		swap(&(*a)->value, &(*a)->prev->value);
		ft_putstr_fd("sa\n", 1);
	}
}

void	sb(t_stack **b)
{
	if (stack_size(*b) >= 2)
	{
		swap(&(*b)->value, &(*b)->prev->value);
		ft_putstr_fd("sb\n", 1);
	}
}

void	ss(t_stack **a, t_stack **b)
{
	if (stack_size(*a) >= 2)
		swap(&(*a)->value, &(*a)->prev->value);
	if (stack_size(*b) >= 2)
		swap(&(*b)->value, &(*b)->prev->value);
	ft_putstr_fd("ss\n", 1);
}

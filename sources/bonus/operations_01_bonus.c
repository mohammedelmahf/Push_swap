/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_01_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:10:25 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/15 15:29:51 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

void	sa_(t_stack **a)
{
	if (stack_size(*a) >= 2)
	{
		swap(&(*a)->value, &(*a)->prev->value);
	}
}

void	sb_(t_stack **b)
{
	if (stack_size(*b) >= 2)
	{
		swap(&(*b)->value, &(*b)->prev->value);
	}
}

void	ss_(t_stack **a, t_stack **b)
{
	if (stack_size(*a) >= 2)
		swap(&(*a)->value, &(*a)->prev->value);
	if (stack_size(*b) >= 2)
		swap(&(*b)->value, &(*b)->prev->value);
}

void	pa_(t_stack **a, t_stack **b)
{
	if (stack_size(*b))
	{
		push(a, pop(b));
	}
}

void	pb_(t_stack **a, t_stack **b)
{
	if (stack_size(*a))
	{
		push(b, pop(a));
	}
}

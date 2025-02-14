/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:22:41 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/14 18:27:50 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../includes/push_swap_bonus.h"

void	ra_(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*to_bottom;
	int		data;

	if (stack_size(*a) >= 2)
	{
		data = pop(a);
		to_bottom = create_node(data);
		tmp = stack_bottom(*a);
		to_bottom->next = tmp;
		tmp->prev = to_bottom;
	}
}

void	rb_(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*to_bottom;
	int		data;

	if (stack_size(*b) >= 2)
	{
		data = pop(b);
		to_bottom = create_node(data);
		tmp = stack_bottom(*b);
		to_bottom->next = tmp;
		tmp->prev = to_bottom;
	}
}

void	rr_(t_stack **a, t_stack **b)
{
	ra_(a);
	rb_(b);
}

void	rra_(t_stack **a)
{
	t_stack	*bottom;

	if (stack_size(*a) >= 2)
	{
		bottom = stack_bottom(*a);
		bottom->next->prev = NULL;
		(*a)->next = bottom;
		bottom->prev = *a;
		*a = (*a)->next;
		(*a)->next = NULL;
	}
}

void	rrb_(t_stack **b)
{
	t_stack	*bottom;

	if (stack_size(*b) >= 2)
	{
		bottom = stack_bottom(*b);
		bottom->next->prev = NULL;
		(*b)->next = bottom;
		bottom->prev = *b;
		*b = (*b)->next;
		(*b)->next = NULL;
	}
}

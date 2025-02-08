/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:42:34 by aboudiba          #+#    #+#             */
/*   Updated: 2025/02/08 05:36:31 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_range(t_stack *a)
{
	int	range;

	range = 0;
	if (stack_size(a) >= 6 && stack_size(a) <= 16)
		range = 3;
	else if (stack_size(a) <= 100)
		range = 13;
	else if (stack_size(a) <= 500)
		range = 35;
	else
		range = 45;
	return (range);
}

static void	pb_rb(t_stack **a, t_stack **b, int *i)
{
	pb(a, b);
	rb(b);
	(*i)++;
}

int	max_index(t_stack *b)
{
	int	index;

	index = 0;
	while (b && stack_max(b) != b)
	{
		b = b->prev;
		index++;
	}
	return (index);
}

void	max_to_top(t_stack **b)
{
	int	index;
	int	size;

	if (!b || !*b)
		return ;
	size = stack_size(*b);
	index = max_index(*b);
	while (index != 0)
	{
		if (index <= size / 2)
			rb(b);
		else
			rrb(b);
		index = max_index(*b);
	}
}

void	min_to_b(t_stack **a, t_stack **b)
{
	if (stack_min(*a) == top_of_stack(*a))
		pb(a, b);
	else if (stack_min(*a) == top_of_stack(*a)->prev)
	{
		sa(a);
		pb(a, b);
	}
	else if (stack_min(*a) == bot_of_stack(*a)->next)
	{
		rra(a);
		rra(a);
		pb(a, b);
	}
	else if (stack_min(*a) == bot_of_stack(*a))
	{
		rra(a);
		pb(a, b);
	}
	else
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
}

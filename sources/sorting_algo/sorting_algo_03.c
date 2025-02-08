/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_03.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:39:45 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/08 04:29:15 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void	max_to_top(t_stack **b)
{
	int	index;
	int	size;

	size = stack_size(*b);
	while (1)
	{
		index = max_index(*b);
		if (index == 0)
			break ;
		else if (index <= size / 2)
			rb(b);
		else if (index > size / 2)
			rrb(b);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_04.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:43:30 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/08 05:40:26 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	sorted(int a, int b)
{
	return (a < b);
}

int	stack_sorted(t_stack *a, int (*sorted)(int, int))
{
	t_stack	*tmp;

	tmp = a;
	while (tmp->prev)
	{
		if (sorted(tmp->value, tmp->prev->value) == 0)
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}

t_stack	*stack_max(t_stack *a)
{
	t_stack	*max;

	if (!a)
		return (NULL);
	max = a;
	while (a)
	{
		if (a->value > max->value)
			max = a;
		a = a->prev;
	}
	return (max);
}

t_stack	*stack_min(t_stack *a)
{
	t_stack	*min;

	if (!a)
		return (NULL);
	min = a;
	while (a)
	{
		if (a->value < min->value)
			min = a;
		a = a->prev;
	}
	return (min);
}

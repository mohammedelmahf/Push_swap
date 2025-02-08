/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:25:02 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/08 04:29:12 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


void	min_to_stack_b(t_stack **a, t_stack **b)
{
	while (stack_min(*a) != top_of_stack(*a))
	{
		if (stack_min(*a) == bot_of_stack(*a))
			rra(a);
		else
			ra(a);
	}
	pb(a, b);
}

void	insertion_sort(int *arr, int size)
{
	int	i;

	i = 0;
	while (i + 1 < size)
	{
		if (arr[i] > arr[i + 1])
		{
			swap(&arr[i], &arr[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

int	*stack_to_sarray(t_stack *s)
{
	int		*arr;
	t_stack	*tmp;
	int		i;
	int		size;

	i = 0;
	if (!s)
		return (NULL);
	tmp = s;
	size = stack_size(s);
	arr = malloc(size * sizeof(int));
	while (tmp)
	{
		arr[i] = tmp->value;
		i++;
		tmp = tmp->prev;
	}
	insertion_sort(arr, size);
	return (arr);
}

void	pb_rb(t_stack **a, t_stack **b, int *i)
{
	pb(a, b);
	rb(b);
	(*i)++;
}

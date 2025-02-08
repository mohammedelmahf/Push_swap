/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_03.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 05:36:00 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/08 05:36:03 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

int	*stack_to_array(t_stack *s)
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
	if (!arr)
		return (NULL);
	while (tmp)
	{
		arr[i] = tmp->value;
		i++;
		tmp = tmp->prev;
	}
	insertion_sort(arr, size);
	return (arr);
}

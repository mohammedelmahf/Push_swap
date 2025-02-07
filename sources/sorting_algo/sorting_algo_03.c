/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_03.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:39:45 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/07 18:47:56 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		max_index(t_stack *b)
{
    int index = 0;
    while (b && stack_max(b) != b)
    {
        b = b->prev;
        index++;
    }
    return (index);
}

void	max_to_top(t_stack **b)
{
    int index;
    int size;
    size = stack_size(*b);
    while (1)
    {
        index = max_index(*b);
        if (index == 0)
            break;
        else if (index <= size / 2)
            rb(b);
        else if (index > size / 2)
            rrb(b);
    }
}

int *stack_to_array(t_stack *str)
{
    int *arr;
    int i;
    t_stack *tmp;
    int size;
    
    i = 0;
    if(!str)
        return(NULL);

    tmp = str;
    size = stack_size(str);
    arr = malloc(size*sizeof(int));
    while(tmp)
    {
        arr[i] = tmp->value;
        tmp = tmp->next;
        i++;
    }
    insertion_sort(arr,size);
    return(arr);
}

void    insertion_sort(int *arr, int size)
{
    int i;
    i = 0;

    while(size >= i)
    {
        if(arr[i] > arr[i + 1])
        {
            swap(&arr[i] , &arr[i+1]);
            i = 0;
        }
        else
            i++;
    }
}

int	get_range(t_stack *a)
{
	int size ;
	int range;

	size = stack_size(a);
	range = 0;

	if(size >= 6 && size <= 16)
		range = 3;
	else if(size <= 100)
		range = 13;
	else if(size <= 500)
		range = 35;
	else
		range = 45;
}
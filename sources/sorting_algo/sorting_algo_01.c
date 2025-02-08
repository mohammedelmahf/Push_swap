/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 23:42:54 by aboudiba          #+#    #+#             */
/*   Updated: 2025/02/08 05:27:40 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	start_sort(t_stack **a, t_stack **b)
{
	(void)b;
	if (stack_size(*a) == 2)
		sa(a);
	else if (stack_size(*a) == 3)
		sort_three(a);
	else if (stack_size(*a) == 4)
		sort_four(a, b);
	else if (stack_size(*a) == 5)
		sort_five(a, b);
	else if (stack_size(*a) >= 6)
	{
		sort_more(a, b, get_range(*a), stack_size(*a));
		while (*b)
		{
			max_to_top(b);
			pa(a, b);
		}
	}
}

void    sort_three(t_stack **a)
{
    int top = top_of_stack(*a)->value;
    int mid = top_of_stack(*a)->prev->value;
    int bot = bot_of_stack(*a)->value;

    if(top > mid && mid > bot)
    {
        ra(a);
        sa(a);
    }
    else if(top > mid && bot > mid && top > bot )
        ra(a);
    else if(top < mid && mid > bot && top < bot )
    {
        sa(a);
        ra(a);
    }
    else if(top < mid && top > bot && mid > bot)
        rra(a);
    else
        sa(a);
    
}

void    sort_four(t_stack **a , t_stack **b)
{
	if (stack_min(*a) == bot_of_stack(*a))
		rra(a);
	else if (stack_min(*a) == bot_of_stack(*a)->next)
	{
		rra(a);
		rra(a);
	}
	else if (stack_min(*a) == top_of_stack(*a)->prev)
		sa(a);
	if (!stack_sorted(*a, sorted))
	{
		pb(a, b);
		sort_three(a);
		pa(a, b);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	min_to_b(a, b);
	min_to_b(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	sort_more(t_stack **a, t_stack **b, int range, int size)
{
	int	*sarr;
	int	i;

	sarr = stack_to_array(*a);
	i = 0;
	while (*a)
	{
		if (range + i >= size)
			range = size - i - 1;
		if (top_of_stack(*a)->value <= sarr[i])
			pb_rb(a, b, &i);
		else if ((*a)->value > sarr[i] && (*a)->value <= sarr[range + i])
		{
			pb(a, b);
			if (stack_size(*b) >= 2 && (*b)->value < (*b)->prev->value)
				sb(b);
			i++;
		}
		else
			ra(a);
	}
	free(sarr);
}
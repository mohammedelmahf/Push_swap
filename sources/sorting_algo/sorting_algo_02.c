/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:25:02 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/07 16:22:26 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

// void	min_to_stack_b(t_stack **a, t_stack **b)
// {
// 	if (stack_min(*a) == top_of_stack(*a))
// 		pb(a, b);
// 	else if (stack_min(*a) == top_of_stack(*a)->prev)
// 	{
// 		sa(a);
// 		pb(a, b);
// 	}
// 	else if (stack_min(*a) == bot_of_stack(*a)->next)
// 	{
// 		rra(a);
// 		rra(a);
// 		pb(a, b);
// 	}
// 	else if (stack_min(*a) == bot_of_stack(*a))
// 	{
// 		rra(a);
// 		pb(a, b);
// 	}
// 	else
// 	{
// 		ra(a);
// 		ra(a);
// 		pb(a, b);
// 	}
// }

void	sort_five(t_stack **a, t_stack **b)
{
	min_to_stack_b(a, b);
	min_to_stack_b(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
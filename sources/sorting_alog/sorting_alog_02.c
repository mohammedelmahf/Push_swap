/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_alog_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:25:02 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/07 12:25:09 by maelmahf         ###   ########.fr       */
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

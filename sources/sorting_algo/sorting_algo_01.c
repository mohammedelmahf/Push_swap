/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:40:23 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/07 18:35:18 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/push_swap.h"

void	start_sort(t_stack **a , t_stack **b)
{
    //void(b);
    if(stack_size(*a) == 2)
        sa(a);
    else if(stack_size(*a) == 3)
        sort_three(a);
    else if(stack_size(*a) == 4)
        sort_four(a, b);
    else if(stack_size(*a) == 5)
        sort_five(a, b);
    else if(stack_size(*a) >= 6)
    {
        sort_more(a , b ,get_range(*a) , stack_size(*a));
        while(*b)
        {
            max_to_top(b);
            pa(a,b);
        }
    }
    
}

void    sort_more(t_stack **a , t_stack **b ,int range , int size)
{
    
}
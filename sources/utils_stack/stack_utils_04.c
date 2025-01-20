/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_04.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:43:30 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/20 14:40:21 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int     sorted(int a , int b)
{
    return(a < b);
}

int     stack_sorted(t_stack *a , int (*sorted)(int , int))
{
    t_stack *tmp;

    tmp = a;
    while(tmp->prev)
    {
        if(sorted(tmp->value, tmp->prev->value) == 0)
            return(0);
        tmp = tmp->prev;
    }
    return(1);
}


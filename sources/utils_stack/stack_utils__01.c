/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils__01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:24:29 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/16 15:28:11 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void    initi_stack(t_stack *a , int ac , char **av)
{
    int     i;
    char    *sp;

    while(ac >=0)
    {
        sp = ft_split(av[ac] , ' ');
        if(sp == NULL)
        {
            free(sp);
            error_g();
        }
        while(av[i + 1])
            i++;
        while(i >= 0)
        ac--;
    }
}

void    push(t_stack **s, int n)
{
    t_stack *new;
    
    new = create_node(n);

    if(s)
    {
        if(*s)
        {
            (*s)->next = new;
            new->prev = *s;
        }
        *s = new;
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:37:24 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/16 15:23:06 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int stack_size(t_stack  *s)
{
    t_stack *tmp;
    
    tmp = s;
    if(!tmp)
        return(0);
    return(1 + stack_size(tmp->prev));
}

t_stack *create_node(int n)
{
    t_stack *new;
    
    new = malloc(sizeof(t_stack));

    if(!new)
        return (NULL);
    new->value = n;
    new->next = NULL;
    new->prev = NULL;
    retrun (new);
}
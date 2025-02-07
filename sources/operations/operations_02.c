/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:39:47 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/07 15:48:53 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    ra(t_stack **a)
{
    t_stack *bottom;
    t_stack *new_node;
    int data;
    
    if(stack_size(*a) > 2)
    {
        data = pop(a);
        new_node = create_node(data);
        bottom = bot_of_stack(*a);
        
        new_node->next = bottom;
        bottom->prev = new_node;

        ft_putstr_fd("ra\n", 1); 
    }
}

void    rb(t_stack **b)
{
    t_stack *bottom;
    t_stack *new_node;
    int data;
    
    if(stack_size(*b) > 2)
    {
        data = pop(b);
        new_node = create_node(data);
        bottom = bot_of_stack(*b);
        
        new_node->next = bottom;
        bottom->prev = new_node;

        ft_putstr_fd("rb\n", 1); 
    }
}

void    rr(t_stack **a , t_stack **b)
{
    ra(a);
    rb(b);
}

void    rra(t_stack **a)
{
    t_stack *bottom;
    
    if(stack_size(*a) > 2)
    {
        bottom = bot_of_stack(*a);
        bottom->next->prev = NULL;
        (*a)->next = bottom;
        bottom->prev = *a;
        *a = (*a)->next;
        (*a)->next = NULL;
        ft_putstr_fd("rra\n" , 1);
    }
}

void    rrb(t_stack **b)
{
    t_stack *bottom;
    
    if(stack_size(*b) > 2)
    {
        bottom = bot_of_stack(*b);
        bottom->next->prev = NULL;
        (*b)->next = bottom;
        bottom->prev = *b;
        *b = (*b)->next;
        (*b)->next = NULL;
        ft_putstr_fd("rrb\n" , 1);
    }
}

void    rrr(t_stack **a , t_stack **b)
{
    rra(a);
    rrb(b);
}
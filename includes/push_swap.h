/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:05:08 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/16 15:25:46 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

typedef struct  s_stack
{
    int                 value;
    struct s_stack *next;
    struct s_stack *prev;
}                       t_stack;

//sources/error
void				error_g(void);
//sources/utils_stack
void					swap(int *a, int *b);
void					initi_stack(t_stack *a , int ac , char **av);
int						stack_size(t_stack  *s);
t_stack					*create_node(int n);
//sources/operations
void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);
#endif
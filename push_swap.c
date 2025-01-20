/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:57:16 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/20 13:51:52 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/push_swap.h"

int	main(int ac , char **av)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    if(ac == 1 || (ac == 2 && !av[1][0]))
        return(0);
    else
        initi_stack(&a , ac -2 , av + 1);
    if(stack_sorted(a , sorted) == 0)
        start_sort(&a , &b);
    free_stack(&a);
    return(0);
}

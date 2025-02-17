/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:57:16 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/17 16:11:24 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	else
		initi_stack(&a, ac - 1, av + 1);
	if (stack_sorted(a, sorted) == 0)
		start_sort(&a, &b);
	free_stack(&a);
	return (0);
}

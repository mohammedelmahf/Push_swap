/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:24:29 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/19 16:04:07 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void			initi_stack(t_stack **a, int ac, char **av)
{
	int			i;
	char		**sp;

	while(ac >= 0)
	{
		sp = ft_split(av[ac] , ' ');
		if(sp == NULL)
		{
			free(sp);
			error_message();
		}
		i = 0;
		while(sp[i + 1])
			i++;
		while(i >= 0)
		{
			if(check_number_if_is_valide(sp[i]) || error_dup(*a , ft_atol(sp[i])))
			{
				free(sp);
				error_message();
			}
			push(a , ft_atol(sp[i]));
			i--;
		}
		i = 0;
		free(sp);
		ac--;
	}
}

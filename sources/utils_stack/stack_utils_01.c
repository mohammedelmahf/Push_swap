/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:24:29 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/21 19:55:10 by maelmahf         ###   ########.fr       */
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
			error_message();
		i = 0;
		while(sp[i])
			i++;
		while(i > 0)
		{
			i--;
			if(check_number_if_is_valide(sp[i]) || error_dup(*a , longlong_atoi(sp[i])))
				error_message();
			push(a , longlong_atoi(sp[i]));
			
		}
		i = 0;
		free_split(sp);
		ac--;
	}
}

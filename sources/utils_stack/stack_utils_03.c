/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_03.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:09:13 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/15 15:57:35 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long long	longlong_atoll(const char *s)
{
	long long	reslt;
	int			sign;

	reslt = 0;
	sign = 1;
	while (*s && ((*s >= 9 && *s <= 13) || *s == ' '))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s && (*s >= '0' && *s <= '9'))
	{
		if (reslt > (LLONG_MAX / 10))
			return_value_with_check(sign, 0);
		if (reslt == (LLONG_MAX / 10) && (*s - '0') > (LLONG_MAX % 10))
			return_value_with_check(sign, 1);
		reslt = reslt * 10 + (*s - '0');
		s++;
	}
	return (sign * reslt);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

t_stack	*bot_of_stack(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->prev)
		a = a->prev;
	return (a);
}

t_stack	*top_of_stack(t_stack *a)
{
	if (!a)
		return (NULL);
	return (a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_03.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:09:13 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/17 16:09:14 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	skip_spaces_and_check_sign(const char **s)
{
	int	sign;

	sign = 1;
	while (**s && ((**s >= 9 && **s <= 13) || **s == ' '))
		(*s)++;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			sign = -1;
		(*s)++;
	}
	return (sign);
}

long long	convert_to_longlong(const char *s, int sign)
{
	long long	reslt;

	reslt = 0;
	while (*s && (*s >= '0' && *s <= '9'))
	{
		if (reslt > (LLONG_MAX / 10))
		{
			if (sign == 1)
				return (LLONG_MAX);
			else
				return (LLONG_MIN);
		}
		if (reslt == (LLONG_MAX / 10) && (*s - '0') > (LLONG_MAX % 10))
		{
			if (sign == 1)
				return (LLONG_MAX);
			else
				return (LLONG_MIN);
		}
		reslt = reslt * 10 + (*s - '0');
		s++;
	}
	return (sign * reslt);
}

long long	longlong_atoi(const char *s)
{
	int	sign;

	sign = skip_spaces_and_check_sign(&s);
	return (convert_to_longlong(s, sign));
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;	

	if (!*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->prev;
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

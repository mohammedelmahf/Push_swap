/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:51:28 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/08 05:31:27 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	error_message(void)
{
	ft_printf("Error\n");
	exit(0);
}

int	check_number_if_is_valide(char *s)
{
	int	i;

	i = 0;
	if (!(s[i] == '-' || s[i] == '+' || ft_isdigit(s[i])))
		return (1);
	if ((s[i] == '-' || s[i] == '+') && !ft_isdigit(s[++i]))
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (1);
		i++;
	}
	return (0);
}

int	error_dup(t_stack *a, long long n)
{
	t_stack	*tmp;

	tmp = a;
	if (n < -2147483648 || n > 2147483647)
		return (1);
	if (!a)
		return (0);
	while (tmp)
	{
		if (tmp->value == n)
			return (1);
		tmp = tmp->prev;
	}
	return (0);
}

int	is_valid_int(const char *str)
{
	long	num;

	num = atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (1);
	return (0);
}

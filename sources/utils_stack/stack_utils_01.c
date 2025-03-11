/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:24:29 by maelmahf          #+#    #+#             */
/*   Updated: 2025/03/11 17:09:44 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	validate_argument(char *arg)
{
	int	j;

	if (!arg || arg[0] == '\0')
	{
		ft_printf("Error\n");
		return (1);
	}
	j = 0;
	while (arg[j] == ' ')
		j++;
	if (arg[j] == '\0')
	{
		ft_printf("Error\n");
		exit(1);
	}
	return (0);
}

char	**split_and_validate_argument(char *arg)
{
	char	**sp;

	sp = ft_split(arg, ' ');
	if (!sp || !sp[0])
	{
		free_split(sp);
		ft_printf("Error\n");
		exit(1);
	}
	return (sp);
}

void	push_values_and_check(char **sp, t_stack **a, int i)
{
	if (!sp[i])
	{
		free_stack(a);
		free_split(sp);
		ft_printf("Error\n");
		exit(1);
	}
	if (check_number_if_is_valide(sp[i])
		|| error_dup(*a, longlong_atoi(sp[i]))
		|| is_valid_int(sp[i]))
	{
		free_stack(a);
		free_split(sp);
		ft_printf("Error\n");
		exit(1);
	}
	push(a, longlong_atoi(sp[i]));
}

void	push_values_to_stack(char **sp, t_stack **a)
{
	int	i;

	i = 0;
	while (sp[i + 1])
		i++;
	while (i >= 0)
	{
		push_values_and_check(sp, a, i);
		i--;
	}
}

void	initi_stack(t_stack **a, int ac, char **av)
{
	char	**sp;

	while (ac > 0)
	{
		if (!av[0] || av[0][0] == '\0')
		{
			ft_printf("Error\n");
			exit(1);
		}
		if (validate_argument(av[ac - 1]))
		{
			free_stack(a);
			exit(1);
		}
		sp = split_and_validate_argument(av[ac - 1]);
		push_values_to_stack(sp, a);
		free_split(sp);
		ac--;
	}
}

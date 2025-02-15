/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:24:29 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/15 15:51:13 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_empty_arg(char *arg)
{
	int	j;

	if (!arg || arg[0] == '\0')
	{
		ft_printf("Error\n");
		exit(1);
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

void	validate_split(char **sp)
{
	if (!sp || !sp[0])
	{
		free_split(sp);
		ft_printf("Error\n");
		exit(1);
	}
}

void	push_split_to_stack(char **sp, t_stack **a)
{
	int	i;

	i = 0;
	while (sp[i + 1])
		i++;
	while (i >= 0)
	{
		if (!sp[i] || check_number_if_is_valide(sp[i])
			|| error_dup(*a, longlong_atoll(sp[i]))
			|| is_valid_int(sp[i]))
		{
			free_stack(a);
			free_split(sp);
			ft_printf("Error\n");
			exit(1);
		}
		push(a, longlong_atoll(sp[i]));
		i--;
	}
	free_split(sp);
}

void	process_split(char **sp, t_stack **a)
{
	validate_split(sp);
	push_split_to_stack(sp, a);
}

void	initi_stack(t_stack **a, int ac, char **av)
{
	char	**sp;

	while (ac > 0)
	{
		check_empty_arg(av[ac - 1]);
		sp = ft_split(av[ac - 1], ' ');
		process_split(sp, a);
		ac--;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:10:29 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/15 15:11:46 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

void	apply_operations(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "sa\n", ft_strlen(line)) == 0)
		sa_(a);
	else if (ft_strncmp(line, "sb\n", ft_strlen(line)) == 0)
		sb_(b);
	else if (ft_strncmp(line, "ss\n", ft_strlen(line)) == 0)
		ss_(a, b);
	else if (ft_strncmp(line, "pa\n", ft_strlen(line)) == 0)
		pa_(a, b);
	else if (ft_strncmp(line, "pb\n", ft_strlen(line)) == 0)
		pb_(a, b);
	else if (ft_strncmp(line, "ra\n", ft_strlen(line)) == 0)
		ra_(a);
	else if (ft_strncmp(line, "rb\n", ft_strlen(line)) == 0)
		rb_(b);
	else if (ft_strncmp(line, "rr\n", ft_strlen(line)) == 0)
		rr_(a, b);
	else if (ft_strncmp(line, "rra\n", ft_strlen(line)) == 0)
		rra_(a);
	else if (ft_strncmp(line, "rrb\n", ft_strlen(line)) == 0)
		rrb_(b);
	else if (ft_strncmp(line, "rrr\n", ft_strlen(line)) == 0)
		rrr_(a, b);
	else
		error_message();
}

void	start_cheking(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		apply_operations(a, b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	else
		initi_stack(&a, ac - 1, av + 1);
	if (stack_sorted(a, sorted) == 0)
	{
		start_cheking(&a, &b);
		if (stack_sorted(a, sorted) == 1 && !b)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	else
		ft_printf("OK\n");
	free_stack(&a);
	if (b)
		free_stack(&b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:37:24 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/17 16:09:57 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	stack_size(t_stack *s)
{
	t_stack	*tmp;

	tmp = s;
	if (!tmp)
		return (0);
	return (1 + stack_size(tmp->prev));
}

t_stack	*create_node(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = n;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	push(t_stack **s, int n)
{
	t_stack	*new;

	new = create_node(n);
	if (s)
	{
		if (*s)
		{
			(*s)->next = new;
			new->prev = *s;
		}
		*s = new;
	}
}

int	pop(t_stack **stack)
{
	int		popped;
	t_stack	*tmp;

	if (!*stack)
		return (0);
	tmp = *stack;
	*stack = (*stack)->prev;
	if (*stack)
		(*stack)->next = NULL;
	popped = tmp->value;
	free(tmp);
	return (popped);
}

t_stack	*bot_of_stack(t_stack *a)
{
	t_stack	*tmp;

	if (!a)
		return (NULL);
	tmp = a;
	while (tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}

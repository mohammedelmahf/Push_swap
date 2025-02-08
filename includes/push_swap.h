/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:05:08 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/08 05:40:59 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// sources/error
void			error_message(void);
int				error_dup(t_stack *a, long long n);
int				check_number_if_is_valide(char *s);

// sources/utils_stack
void			swap(int *a, int *b);
void			initi_stack(t_stack **a, int ac, char **av);
int				stack_size(t_stack *s);
t_stack			*create_node(int n);
long long		longlong_atoi(const char *s);
void			push(t_stack **s, int n);
void			free_stack(t_stack **stack);
int				pop(t_stack **stack);
void			free_split(char **sp);
int				stack_sorted(t_stack *a, int (*sorted)(int, int));
int				sorted(int a, int b);
t_stack			*top_of_stack(t_stack *a);
t_stack			*bot_of_stack(t_stack *a);
t_stack			*stack_max(t_stack *a);
t_stack			*stack_min(t_stack *a);
int				is_valid_int(const char *str);

// sources/operations
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);
void			rb(t_stack **b);
void			ra(t_stack **a);
void			rr(t_stack **a, t_stack **b);
void			rrr(t_stack **a, t_stack **b);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **a, t_stack **b);

// sources/sorting_algo
void			start_sort(t_stack **a, t_stack **b);
void			sort_three(t_stack **a);
void			sort_four(t_stack **a, t_stack **b);
void			sort_five(t_stack **a, t_stack **b);
void			min_to_stack_b(t_stack **a, t_stack **b);
int				max_index(t_stack *b);
void			max_to_top(t_stack **b);
void			insertion_sort(int *arr, int size);
int				*stack_to_array(t_stack *str);
int				get_range(t_stack *a);
void			sort_more(t_stack **a, t_stack **b, int range, int size);

#endif

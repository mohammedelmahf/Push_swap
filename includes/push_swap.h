/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:05:08 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/21 11:35:52 by maelmahf         ###   ########.fr       */
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
long long		ft_atol(const char *s);
void			push(t_stack **s, int n);
void			free_stack(t_stack **stack);
int				pop(t_stack **stack);
void			free_split(char **sp);
int				stack_sorted(t_stack *a , int (*sorted)(int , int));
int				sorted(int a , int b);
t_stack			*top_of_stack(t_stack *a);
t_stack			*bottom_of_stack(t_stack *a);
t_stack			*stack(t_stack *a);
t_stack			*stack(t_stack *a);
// sources/operations
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);
//sources/sorting_algo
void	start_sort(t_stack **a , t_stack **b);
#endif

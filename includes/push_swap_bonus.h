/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:23:05 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/14 18:38:08 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H 
#define PUSH_SWAP_BONUS_H 


#include"push_swap.h"
#include"get_next_line.h"

void	sa_(t_stack **a);
void	sb_(t_stack **b);
void	ss_(t_stack **a, t_stack **b);
void	pa_(t_stack **a, t_stack **b);
void	pb_(t_stack **a, t_stack **b);
void	ra_(t_stack **a);
void	rb_(t_stack **b);
void	rr_(t_stack **a, t_stack **b);
void	rra_(t_stack **a);
void	rrr_(t_stack **a, t_stack **b);
void	rrb_(t_stack **b);
void	apply_operations(t_stack **a, t_stack **b, char *line);
void	start_cheking(t_stack **a, t_stack **b);
#endif
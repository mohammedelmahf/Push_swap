/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:10:57 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/07 11:20:25 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int	stack_size(t_stack *s);
t_stack	*create_node(int n);
t_stack		*bot_of_stack(t_stack *a);
void	ft_putstr_fd(char *s, int fd);
int	pop(t_stack **stack);
void    rb(t_stack **b);
void    rb(t_stack **b);
void	push(t_stack **s, int n);
size_t	ft_strlen(const char *str);
void    print_stack(t_stack *stack);

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

void	ft_putstr_fd(char *s, int fd)
{
	if (fd >= 0 && s)
		write(fd, s, ft_strlen(s));
}


t_stack		*bot_of_stack(t_stack *a)
{
	t_stack *tmp;

	if(!a)
		return(NULL);
	tmp = a;
	if(tmp->prev)
		tmp = tmp->prev;
	return(tmp);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void    print_stack(t_stack *stack)
{
    t_stack *temp;
    
    temp = stack;
    if (!temp)
    {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack contents (top to bottom):\n");
    while (temp)
    {
        printf("%d", temp->value);
        if (temp->next)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
    
    // Print stack size
    int size = stack_size(stack);
    printf("Stack size: %d\n", size);
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

int	stack_size(t_stack *s)
{
	t_stack	*tmp;

	tmp = s;
	if (!tmp)
		return (0);
	return (1 + stack_size(tmp->prev));
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

void    rb(t_stack **b)
{
    t_stack *bottom;
    t_stack *new_node;
    int data;
    
    if(stack_size(*b) > 2)
    {
        data = pop(b);
        new_node = create_node(data);
        bottom = bot_of_stack(*b);
        
        new_node->next = bottom;
        bottom->prev = new_node;

        ft_putstr_fd("rb\n", 1); 
    }
}

int main(void)
{
    t_stack *stack_b = NULL;
    
    // Initialize stack with some test values
    // Pushing values 1, 2, 3 (bottom to top)
    push(&stack_b, 1);
    push(&stack_b, 2);
    push(&stack_b, 3);
    
    printf("Original stack b:\n");
    while(stack_b)
    {
        print_stack(stack_b);
        break;
    }
    // Test rb operation
    rb(&stack_b);
    
    printf("\nAfter rb operation:\n");
    print_stack(stack_b);
    
    // Clean up memory
    while (stack_b != NULL)
    {
        pop(&stack_b);
    }
    
    return (0);
}
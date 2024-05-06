/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:17:42 by jtakahas          #+#    #+#             */
/*   Updated: 2024/05/06 21:25:37 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int data)
{
	t_node		*new_node;
	t_command	command;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		malloc_error_print();
	command = command_init();
	new_node->data = data;
	new_node->command = command;
	if (is_empty(stack))
	{
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	else
	{
		new_node->next = stack->top;
		new_node->prev = stack->top->prev;
		stack->top->prev->next = new_node;
		stack->top->prev = new_node;
	}
	stack->top = new_node;
}

void	push_to(t_stack *from, t_stack *to, char c)
{
	int		data;

	if (is_empty(from))
		return ;
	data = from->top->data;
	if (from->top->next == from->top)
		from->top = NULL;
	else
	{
		from->top->prev->next = from->top->next;
		from->top->next->prev = from->top->prev;
		from->top = from->top->next;
	}
	push(to, data);
	ft_printf("p%c\n", c);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push_to(stack_b, stack_a, 'a');
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push_to(stack_a, stack_b, 'b');
}

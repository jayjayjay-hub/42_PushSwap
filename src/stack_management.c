/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:33:37 by jtakahas          #+#    #+#             */
/*   Updated: 2024/05/06 19:41:58 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *stack, t_stack *stack_b)
{
	stack->top = NULL;
	stack_b->top = NULL;
}

void	both_stack_index_init(t_stack *stack_a, t_stack *stack_b)
{
	stack_index_init(stack_a);
	stack_index_init(stack_b);
}

void	stack_index_init(t_stack *stack)
{
	t_node	*temp;
	int		index;

	temp = stack->top;
	index = 0;
	while (temp->next != stack->top)
	{
		temp->index = index;
		temp = temp->next;
		index++;
	}
	temp->index = index;
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;
	t_node	*next;

	if (is_empty(stack))
		return ;
	temp = stack->top;
	while (temp->next != stack->top)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	free(temp);
	stack->top = NULL;
}

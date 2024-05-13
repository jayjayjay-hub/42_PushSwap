/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:18:24 by jtakahas          #+#    #+#             */
/*   Updated: 2024/05/06 16:18:31 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack, char c)
{
	if (is_empty(stack) || stack->top->next == stack->top)
		return ;
	stack->top = stack->top->prev;
	ft_printf("rr%c\n", c);
}

void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a, 'a');
}

void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b, 'b');
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a, 'a');
	reverse_rotate(stack_b, 'b');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:18:44 by jtakahas          #+#    #+#             */
/*   Updated: 2024/05/06 16:18:49 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, char c)
{
	if (is_empty(stack) || stack->top->next == stack->top)
		return ;
	stack->top = stack->top->next;
	ft_printf("r%c\n", c);
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a, 'a');
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b, 'b');
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, 'a');
	rotate(stack_b, 'b');
}

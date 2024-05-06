/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:19:40 by jtakahas          #+#    #+#             */
/*   Updated: 2024/05/06 18:39:36 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_len_3(t_stack *stack)
{
	int	max_data;

	max_data = get_max_data(stack);
	if (max_data == stack->top->data)
		ra(stack);
	else if (max_data == stack->top->next->data)
		rra(stack);
	if (stack->top->data > stack->top->next->data)
		sa(stack);
}

void	push_swap(int len, t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) || len == 1)
		return ;
	if (len == 2)
		sa(stack_a);
	else if (len == 3)
		sort_len_3(stack_a);
	else
		sort(stack_a, stack_b);
}

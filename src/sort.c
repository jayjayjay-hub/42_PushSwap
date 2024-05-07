/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:45:33 by jtakahas          #+#    #+#             */
/*   Updated: 2024/05/07 16:01:01 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target_from_b(t_stack *stack_b, int data)
{
	t_node	*temp;
	int		target;
	int		max;
	int		min;
	int		len;

	temp = stack_b->top;
	max = get_max_data(stack_b);
	min = get_min_data(stack_b);
	len = get_len_stack(stack_b);
	if (data > max || data < min)
		return (max);
	target = min;
	while (len > 0)
	{
		if (temp->data < data && temp->data > target)
			target = temp->data;
		temp = temp->next;
		len--;
	}
	return (target);
}

int	get_target_from_a(t_stack *stack_a, int data)
{
	t_node	*temp;
	int		target;
	int		a_max;
	int		a_min;
	int		len_a;

	temp = stack_a->top;
	a_max = get_max_data(stack_a);
	a_min = get_min_data(stack_a);
	len_a = get_len_stack(stack_a);
	if (data > a_max)
		return (a_min);
	if (data < a_min)
		return (a_min);
	target = a_max;
	while (len_a > 0)
	{
		if (temp->data > data && temp->data < target)
			target = temp->data;
		temp = temp->next;
		len_a--;
	}
	return (target);
}

static void	sort_reverse(t_stack *stack)
{
	int	min;
	int	min_index;
	int	len;

	min = get_min_data(stack);
	min_index = get_index_from_data(stack, min);
	len = get_len_stack(stack);
	if (min_index <= len / 2)
	{
		while (stack->top->data != min)
			ra(stack);
	}
	else
	{
		while (stack->top->data != min)
			rra(stack);
	}
}

bool	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_command	*command;

	if (!pb(stack_a, stack_b))
		return (false);
	if (!pb(stack_a, stack_b))
		return (false);
	while (get_len_stack(stack_a) > 3)
	{
		both_stack_index_init(stack_a, stack_b);
		command = serch_optimal_command_push_to_b(stack_a, stack_b);
		do_command(*command, stack_a, stack_b);
		if (!pb(stack_a, stack_b))
			return (false);
	}
	sort_len_3(stack_a);
	while (get_len_stack(stack_b) > 0)
	{
		both_stack_index_init(stack_a, stack_b);
		command = serch_optimal_command_push_to_a(stack_a, stack_b);
		do_command(*command, stack_a, stack_b);
		if (!pa(stack_a, stack_b))
			return (false);
	}
	sort_reverse(stack_a);
	return (true);
}

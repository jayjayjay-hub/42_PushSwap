/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:46:44 by jtakahas          #+#    #+#             */
/*   Updated: 2024/05/06 21:49:40 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	register_command_push_a(t_stack *stack_a,
								t_stack *stack_b,
								int b_data,
								t_command *command)
{
	int	target_data;
	int	target_index;
	int	b_index;
	int	len_a;
	int	len_b;

	target_data = get_target_from_a(stack_a, b_data);
	target_index = get_index_from_data(stack_a, target_data);
	b_index = get_index_from_data(stack_b, b_data);
	len_a = get_len_stack(stack_a);
	len_b = get_len_stack(stack_b);
	*command = calculation_command(target_index, b_index, len_a, len_b);
}

void	register_command_push_b(t_stack *stack_a,
								t_stack *stack_b,
								int a_data,
								t_command *command)
{
	int		target_data;
	int		target_index;
	int		a_index;

	target_data = get_target_from_b(stack_b, a_data);
	target_index = get_index_from_data(stack_b, target_data);
	a_index = get_index_from_data(stack_a, a_data);
	*command = calculation_command(a_index,
			target_index,
			get_len_stack(stack_a),
			get_len_stack(stack_b));
}

t_command	*serch_optimal_command_push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int			b_len;
	t_node		*temp_b;
	t_command	*optimal_command;

	both_stack_index_init(stack_a, stack_b);
	b_len = get_len_stack(stack_b);
	temp_b = stack_b->top;
	optimal_command = &temp_b->command;
	register_command_push_a(stack_a, stack_b, temp_b->data, optimal_command);
	while (b_len > 0)
	{
		if (optimal_command->all <= 1)
			return (optimal_command);
		register_command_push_a(stack_a,
			stack_b,
			temp_b->data,
			&temp_b->command);
		if (temp_b->command.all < optimal_command->all)
			optimal_command = &temp_b->command;
		temp_b = temp_b->next;
		b_len--;
	}
	return (optimal_command);
}

t_command	*serch_optimal_command_push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int			a_len;
	t_node		*temp_a;
	t_command	*optimal_command;

	both_stack_index_init(stack_a, stack_b);
	a_len = get_len_stack(stack_a);
	temp_a = stack_a->top;
	optimal_command = &temp_a->command;
	register_command_push_b(stack_a, stack_b, temp_a->data, optimal_command);
	while (a_len > 0)
	{
		if (optimal_command->all <= 1)
			return (optimal_command);
		register_command_push_b(stack_a, stack_b,
			temp_a->data,
			&temp_a->command);
		if (temp_a->command.all < optimal_command->all)
			optimal_command = &temp_a->command;
		temp_a = temp_a->next;
		a_len--;
	}
	return (optimal_command);
}

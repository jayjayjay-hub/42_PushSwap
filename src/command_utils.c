/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:23:39 by jtakahas          #+#    #+#             */
/*   Updated: 2024/05/06 21:26:35 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_command	command_init(void)
{
	t_command	command;

	command.all = 0;
	command.ra = 0;
	command.rra = 0;
	command.rb = 0;
	command.rrb = 0;
	command.rr = 0;
	command.rrr = 0;
	return (command);
}

static int	rotate_count_with_ab(a_count, b_count)
{
	int	with;

	if (a_count <= b_count)
		with = a_count;
	else
		with = b_count;
	return (with + ft_abs(a_count - b_count));
}

static int	get_smallest(int ra_rb, int rra_rrb, int ra_rrb, int rra_rb)
{
	if (ra_rb <= rra_rrb
		&& ra_rb <= ra_rrb
		&& ra_rb <= rra_rb)
		return (RA_RB);
	if (rra_rrb <= ra_rb
		&& rra_rrb <= ra_rrb
		&& rra_rrb <= rra_rb)
		return (RRA_RRB);
	if (ra_rrb <= ra_rb
		&& ra_rrb <= rra_rrb
		&& ra_rrb <= rra_rb)
		return (RA_RRB);
	return (RRA_RB);
}

t_command	calculation_command(int a_index, int b_index, int a_len, int b_len)
{
	int			ra_rb;
	int			rra_rrb;
	int			ra_rrb;
	int			rra_rb;
	t_command	command;

	ra_rb = rotate_count_with_ab(a_index, b_index);
	rra_rrb = rotate_count_with_ab(a_len - a_index, b_len - b_index);
	ra_rrb = a_index + b_len - b_index;
	rra_rb = a_len - a_index + b_index;
	command = command_init();
	if (get_smallest(ra_rb, rra_rrb, ra_rrb, rra_rb) == RA_RB)
		commnad_set_rarb(&command, a_index, b_index);
	else if (get_smallest(ra_rb, rra_rrb, ra_rrb, rra_rb) == RRA_RRB)
		commnad_set_rrarrb(&command, a_len - a_index, b_len - b_index);
	else if (get_smallest(ra_rb, rra_rrb, ra_rrb, rra_rb) == RA_RRB)
		command_set_rarrb(&command, a_index, b_len - b_index);
	else if (get_smallest(ra_rb, rra_rrb, ra_rrb, rra_rb) == RRA_RB)
		command_set_rrarb(&command, a_len - a_index, b_index);
	return (command);
}

void	do_command(t_command command, t_stack *stack_a, t_stack *stack_b)
{
	while (command.rr-- > 0)
		rr(stack_a, stack_b);
	while (command.ra-- > 0)
		ra(stack_a);
	while (command.rb-- > 0)
		rb(stack_b);
	while (command.rrr-- > 0)
		rrr(stack_a, stack_b);
	while (command.rra-- > 0)
		rra(stack_a);
	while (command.rrb-- > 0)
		rrb(stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:28:53 by jtakahas          #+#    #+#             */
/*   Updated: 2024/05/06 21:13:54 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	commnad_set_rarb(t_command *command, int ra_count, int rb_count)
{
	if (ra_count <= rb_count)
	{
		command->ra = 0;
		command->rb = rb_count - ra_count;
		command->rr = ra_count;
	}
	else
	{
		command->ra = ra_count - rb_count;
		command->rb = 0;
		command->rr = rb_count;
	}
	command->rra = 0;
	command->rrb = 0;
	command->rrr = 0;
	command->all = command->rr + ft_abs(ra_count - rb_count);
}

void	commnad_set_rrarrb(t_command *command, int rra_count, int rrb_count)
{
	if (rra_count <= rrb_count)
	{
		command->rra = 0;
		command->rrb = rrb_count - rra_count;
		command->rrr = rra_count;
	}
	else
	{
		command->rra = rra_count - rrb_count;
		command->rrb = 0;
		command->rrr = rrb_count;
	}
	command->ra = 0;
	command->rb = 0;
	command->rr = 0;
	command->all = command->rrr + ft_abs(rra_count - rrb_count);
}

void	command_set_rarrb(t_command *command, int ra_count, int rrb_count)
{
	command->ra = ra_count;
	command->rb = 0;
	command->rra = 0;
	command->rrb = rrb_count;
	command->rr = 0;
	command->rrr = 0;
	command->all = ra_count + rrb_count;
}

void	command_set_rrarb(t_command *command, int rra_count, int rb_count)
{
	command->ra = 0;
	command->rb = rb_count;
	command->rra = rra_count;
	command->rrb = 0;
	command->rr = 0;
	command->rrr = 0;
	command->all = rra_count + rb_count;
}

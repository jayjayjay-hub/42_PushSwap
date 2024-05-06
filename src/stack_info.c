/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:25:52 by jtakahas          #+#    #+#             */
/*   Updated: 2024/05/06 16:54:36 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_len_stack(t_stack *stack)
{
	int		len;
	t_node	*temp;

	if (is_empty(stack))
		return (0);
	len = 1;
	temp = stack->top;
	while (temp->next != stack->top)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

int	get_max_data(t_stack *stack)
{
	t_node	*temp;
	int		max;
	int		len;

	temp = stack->top;
	max = temp->data;
	len = get_len_stack(stack);
	while (len > 0)
	{
		if (temp->data > max)
			max = temp->data;
		temp = temp->next;
		len--;
	}
	return (max);
}

int	get_min_data(t_stack *stack)
{
	t_node	*temp;
	int		min;
	int		len;

	temp = stack->top;
	min = temp->data;
	len = get_len_stack(stack);
	while (len > 0)
	{
		if (temp->data < min)
			min = temp->data;
		temp = temp->next;
		len--;
	}
	return (min);
}

int	get_index_from_data(t_stack *stack, int data)
{
	t_node	*temp;
	int		index;

	temp = stack->top;
	index = 0;
	while (temp->next != stack->top)
	{
		if (temp->data == data)
			return (index);
		temp = temp->next;
		index++;
	}
	if (temp->data == data)
		return (index);
	return (-1);
}

void	print_stack(t_stack *stack, char *name)
{
	t_node	*temp;

	if (is_empty(stack))
	{
		ft_printf("%s is empty\n", name);
		return ;
	}
	temp = stack->top;
	ft_printf("%s: ", name);
	while (temp->next != stack->top)
	{
		ft_printf("%d ", temp->data);
		temp = temp->next;
	}
	ft_printf("%d\n", temp->data);
}

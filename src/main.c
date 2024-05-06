/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:03:01 by jtakahas          #+#    #+#             */
/*   Updated: 2024/05/06 16:33:49 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_duplicate(int *array, int len, int data)
{
	int	index;

	index = 0;
	while (index < len)
	{
		if (array[index] == data)
			return (true);
		index++;
	}
	return (false);
}

int	data_set_to_stack(int len_data, t_stack *stack_a, int *data)
{
	int	index;

	index = 0;
	while (index < len_data)
	{
		push(stack_a, data[len_data - index - 1]);
		index++;
	}
	return (0);
}

static void	data_set_to_array(int len_data, char **av, int *data)
{
	int		num_data;
	int		index;

	index = 0;
	while (index < len_data)
	{
		num_data = push_swap_atoi(av[index]);
		if ((num_data == 0 && *av[index] != '0')
			|| is_duplicate(data, index, num_data))
		{
			error_print();
			free(data);
			return ;
		}
		data[index] = num_data;
		index++;
	}
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*data;
	int		len_data;

	if (ac <= 1)
		error_print_exit();
	len_data = ac - 1;
	data = malloc(sizeof(int) * (len_data));
	if (data == NULL)
		error_print_exit();
	data_set_to_array(len_data, ++av, data);
	stack_init(&stack_a, &stack_b);
	data_set_to_stack(len_data, &stack_a, data);
	push_swap(len_data, &stack_a, &stack_b);
	return (0);
}

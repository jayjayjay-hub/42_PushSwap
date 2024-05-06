/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:27:11 by jtakahas          #+#    #+#             */
/*   Updated: 2024/05/05 22:22:14 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_print(void)
{
	ft_printf("Error\n");
}

void	malloc_error_print(void)
{
	ft_printf("Malloc error\n");
	exit(1);
}

void	error_print_exit(void)
{
	ft_printf("Error\n");
	exit(1);
}

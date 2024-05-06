/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:33:28 by jtakahas          #+#    #+#             */
/*   Updated: 2024/05/06 18:25:21 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*pass_space(char *str)
{
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}

static char	*check_plus_minus(char *str, int *sign)
{
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	return (str);
}

static bool	is_int(long long num, int sign)
{
	if (sign == 1 && num > __INT_MAX__)
		return (false);
	if (sign == -1 && num * -1 < INT_MIN)
		return (false);
	return (true);
}

int	push_swap_atoi(char *str)
{
	int			sign;
	long long	ans;

	sign = 1;
	ans = 0;
	str = pass_space(str);
	str = check_plus_minus(str, &sign);
	if (*str == '\0' || str == NULL)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		ans = (*str - '0') + (ans * 10);
		if (!is_int(ans, sign))
			return (0);
		str++;
	}
	return (ans * sign);
}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

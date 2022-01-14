/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:32:39 by calecia           #+#    #+#             */
/*   Updated: 2022/01/14 13:33:25 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	only_digit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

static int	check_sign(char firstSym)
{
	if (firstSym == '-')
		return (-1);
	if (firstSym == '+')
		return (1);
	return (0);
}

static int	max_int(char *str, int sign)
{
	if (sign == 1)
	{
		if (ft_strncmp("2147483647", str, 10) >= 0)
			return (1);
		return (0);
	}
	if (sign == -1)
	{
		if (ft_strncmp("2147483648", str, 10) >= 0)
			return (1);
		return (0);
	}
	return (0);
}

static int	toi(char *str, int sign)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (str[i])
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (sign * num);
}

int	valid_int(char *str)
{
	int	sign;
	int	i;
	int	size_str;

	i = 0;
	sign = check_sign(str[0]);
	if (sign)
		str++;
	else
		sign = 1;
	if (!*str)
	{
		write (STDERR_FILENO, "Error\n", 6);
		exit (1);
	}
	size_str = ft_strlen(str);
	if (size_str > 10 || !only_digit(str)
		|| (size_str == 10 && !max_int(str, sign)))
	{
		write (STDERR_FILENO, "Error\n", 6);
		exit (1);
	}
	return (toi(str, sign));
}

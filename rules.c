/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:34:51 by calecia           #+#    #+#             */
/*   Updated: 2022/01/11 17:12:01 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	rule_swap(t_circle	*a, t_circle *b, char a_b_s)
{
	if (!a || !b)
		return (0);
	if (a_b_s == 'a')
		ft_swap(a);
	else if (a_b_s == 'b')
		ft_swap(b);
	else if (a_b_s == 's')
	{
		ft_swap(a);
		ft_swap(b);
	}
	else
		return (0);
	write(1, "s", 1);
	write(1, &a_b_s, 1);
	write(1, "\n", 1);
	return (1);
}

int	rule_push(t_circle	*a, t_circle *b, char a_b)
{
	if (!a || !b)
		return (0);
	if (a_b == 'a')
		ft_push(b, a);
	else if (a_b == 'b')
		ft_push(a, b);
	else
		return (0);
	write(1, "p", 1);
	write(1, &a_b, 1);
	write(1, "\n", 1);
	return (1);
}

int	rule_rotate(t_circle *a, t_circle *b, char a_b_r)
{
	if (!a || !b)
		return (0);
	if (a_b_r == 'a')
		ft_rotate(a);
	else if (a_b_r == 'b')
		ft_rotate(b);
	else if (a_b_r == 'r')
	{
		ft_rotate(a);
		ft_rotate(b);
	}
	else
		return (0);
	write(1, "r", 1);
	write(1, &a_b_r, 1);
	write(1, "\n", 1);
	return (1);
}

int	rule_reverse_rotate(t_circle *a, t_circle *b, char a_b_r)
{
	if (!a || !b)
		return (0);
	if (a_b_r == 'a')
		ft_rrotate(a);
	else if (a_b_r == 'b')
		ft_rrotate(b);
	else if (a_b_r == 'r')
	{
		ft_rrotate(a);
		ft_rrotate(b);
	}
	else
		return (0);
	write(1, "r", 1);
	write(1, "r", 1);
	write(1, &a_b_r, 1);
	write(1, "\n", 1);
	return (1);
}

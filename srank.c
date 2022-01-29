/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srank.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:53:43 by calecia           #+#    #+#             */
/*   Updated: 2022/01/29 20:17:53 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	side_rotate_a(t_circle *a, int value)
{
	int		count_rotate;
	t_node	*temp;

	count_rotate = 0;
	temp = a->first;
	while (!(temp->data > value && temp->prev->data < value))
	{
		temp = temp->next;
		count_rotate++;
	}
	if (count_rotate < a->size - count_rotate)
	{
		return (1);
	}
	else
	{
		return (-1);
	}
}

int	side_rotate_b(t_circle *b, int count_rotate)
{
	if (count_rotate < b->size - count_rotate)
	{
		return (1);
	}
	else
	{
		return (-1);
	}
}

int	double_rotate(t_circle *a, t_circle *b, int value, int side_rotate)
{
	if (side_rotate == 1)
	{
		while ((!(a->first->data > value && a->first->prev->data < value))
			&& b->first->data != value)
		{
			rule_rotate(a, b, 'r');
		}
	}
	else
	{
		while ((!(a->first->data > value && a->first->prev->data < value))
			&& b->first->data != value)
		{
			rule_reverse_rotate(a, b, 'r');
		}
	}
	return (1);
}

int	needed_double_rotate(t_circle *a, t_circle *b, int min_rank)
{
	t_node	*temp;
	int		count_rotate;
	int		ret;

	temp = b->first;
	count_rotate = 0;
	while (temp->rank != min_rank)
	{
		count_rotate++;
		temp = temp->next;
	}
	ret = side_rotate_a(a, temp->data);
	if (ret != side_rotate_b(b, count_rotate))
		return (0);
	double_rotate(a, b, temp->data, ret);
	return (1);
}

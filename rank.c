/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:11:48 by calecia           #+#    #+#             */
/*   Updated: 2022/01/29 20:22:43 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int	calculate_rank(t_circle *a, int value)
{
	int		count_rotate_a;
	int		i;
	t_node	*temp;

	temp = a->first;
	count_rotate_a = 0;
	i = 0;
	while (!(temp->data > value && temp->prev->data < value))
	{
		i++;
		temp = temp->next;
	}
	count_rotate_a = i;
	temp = a->first;
	i = 0;
	while (!(temp->data > value && temp->prev->data < value))
	{
		i++;
		temp = temp->next;
	}
	if (i < count_rotate_a)
		count_rotate_a = i;
	return (count_rotate_a);
}

int	set_rank(t_circle *a, t_circle *b)
{
	t_node	*temp;
	int		count_rotate_b;
	int		min_rank;

	count_rotate_b = 0;
	temp = b->first;
	temp->rank = calculate_rank(a, temp->data);
	min_rank = temp->rank;
	temp = temp->next;
	while (temp && temp != b->first)
	{
		count_rotate_b++;
		temp->rank = calculate_rank(a, temp->data);
		if (count_rotate_b > b->size - count_rotate_b)
			temp->rank += b->size - count_rotate_b;
		else
			temp->rank += count_rotate_b;
		if (temp->rank < min_rank)
			min_rank = temp->rank;
		temp = temp->next;
	}
	return (min_rank);
}

void	min_rotate_b(t_circle *b, int value_rotated, int count_rotate)
{
	if (count_rotate < b->size - count_rotate)
	{
		while (b->first->data != value_rotated)
		{
			rule_rotate(b, b, 'b');
		}
	}
	else
	{
		while (b->first->data != value_rotated)
		{
			rule_reverse_rotate(b, b, 'b');
		}
	}
}

void	min_rotate_a(t_circle *a, int value)
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
		while (!(a->first->data > value && a->first->prev->data < value))
		{
			rule_rotate(a, a, 'a');
		}
	}
	else
	{
		while (!(a->first->data > value && a->first->prev->data < value))
		{
			rule_reverse_rotate(a, a, 'a');
		}
	}
}

void	push_el_with_min_rank(t_circle *a, t_circle *b, int min_rank)
{
	t_node	*temp;
	int		count_rotate;

	temp = b->first;
	count_rotate = 0;
	while (temp->rank != min_rank)
	{
		count_rotate++;
		temp = temp->next;
	}
	needed_double_rotate(a, b, min_rank);
	if (b->first != temp)
		min_rotate_b(b, temp->data, count_rotate);
	if (!(a->first->data > temp->data && a->first->prev->data < temp->data))
		min_rotate_a(a, temp->data);
	rule_push(a, b, 'a');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:50:01 by calecia           #+#    #+#             */
/*   Updated: 2022/01/28 22:15:05 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	sort_three_digit(t_circle *a)
{
	int		max;
	t_node	*temp;

	max = a->first->prev->data;
	temp = a->first;
	if (a->size != 3)
		return (0);
	while (max != temp->data)
	{
		if (temp->data > max)
			max = temp->data;
		temp = temp->next;
	}
	if (temp->next->data > temp->prev->data)
		rule_swap(a, a, 'a');
	return (1);
}

static void	min_rotate_a(t_circle *a, int value)
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

void	mini_sort(t_circle *a)
{
	t_circle	b;

	b.first = NULL;
	b.size = 0;
	rule_push(a, &b, 'b');
	rule_push(a, &b, 'b');
	sort_three_digit(&b);
	sort_three_digit(a);
	min_rotate_a(a, b.first->data);
	rule_push(a, &b, 'a');
	min_rotate_a(a, b.first->data);
	rule_push(a, &b, 'a');
}

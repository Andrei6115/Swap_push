/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:50:01 by calecia           #+#    #+#             */
/*   Updated: 2022/02/03 21:53:23 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	min_rotate_a(t_circle *a, int value, int flag)
{
	int		count_rotate;
	t_node	*temp;

	count_rotate = 0;
	temp = a->first;
	while (!(temp->data > value && temp->prev->data < value)
		&& !(flag && temp->data < temp->prev->data))
	{
		temp = temp->next;
		count_rotate++;
	}
	if (count_rotate < a->size - count_rotate)
	{
		while (!(a->first->data > value && a->first->prev->data < value)
			&& !(flag && a->first->data < a->first->prev->data))
			rule_rotate(a, a, 'a');
	}
	else
	{
		while (!(a->first->data > value && a->first->prev->data < value)
			&& !(flag && a->first->data < a->first->prev->data))
			rule_reverse_rotate(a, a, 'a');
	}
}

void	rotate(t_circle *a, int min)
{
	t_node		*temp;
	int			i;

	temp = a->first;
	i = 0;
	while (temp->data != min)
	{
		i++;
		temp = temp->next;
	}
	if (i < a->size - i)
		while (a->first->data != min)
			rule_rotate(a, a, 'a');
	else
		while (a->first->data != min)
			rule_reverse_rotate(a, a, 'a');
}

void	clean(t_circle *a)
{
	t_node	*del;

	while (a->first)
	{
		del = a->first;
		a->first->prev->next = NULL;
		a->first = a->first->next;
		free(del);
	}
}

int	sub_func(t_circle *a, t_circle *b)
{
	t_node	*temp;
	int		el;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	el = b->first->data;
	temp = a->first;
	while (i < a->size)
	{
		if (temp->data > el)
			ret++;
		if (temp->data < el)
			ret--;
		temp = temp->next;
		i++;
	}
	if (ret < 0)
		ret *= -1;
	if (ret != a->size)
		return (0);
	return (1);
}

void	mini_sort(t_circle *a, int min, int max)
{
	t_circle	b;

	max = min;
	b.first = NULL;
	b.size = 0;
	rule_push(a, &b, 'b');
	rule_push(a, &b, 'b');
	if (b.first->data > b.first->next->data)
		rule_rotate(a, &b, 'b');
	sort_three_digit(a);
	min_rotate_a(a, b.first->data, sub_func(a, &b));
	rule_push(a, &b, 'a');
	min_rotate_a(a, b.first->data, sub_func(a, &b));
	rule_push(a, &b, 'a');
	rotate(a, min);
	clean(a);
}

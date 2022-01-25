/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 06:42:13 by calecia           #+#    #+#             */
/*   Updated: 2022/01/25 18:48:20 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	sort_three_digit(t_circle *a)
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

t_circle	part_one(t_circle *a, int min, int max, int mid)
{
	t_circle	b;
	int			temp;

	ft_null(&b);
	while (a->size > 3)
	{
		temp = a->first->data;
		if (temp > mid && temp != max && temp != min && temp != mid)
		{
			rule_push(a, &b, 'b');
			rule_rotate(a, &b, 'b');
		}
		else if (temp < mid && temp != max && temp != min && temp != mid)
		{
			rule_push(a, &b, 'b');
		}
		else
			rule_rotate(a, &b, 'a');
	}
	return (b);
}

void	turn_a_to_put_el_from_b(t_circle *a, int el)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = a->first;
	while (!(temp->data > el && temp->prev->data < el))
	{
		i++;
		temp = temp->next;
	}
	if (i > a->size / 2)
	{
		while (!(a->first->data > el && a->first->prev->data < el))
		{
			rule_reverse_rotate(a, a, 'a');
		}
	}
	else
	{
		while (!(a->first->data > el && a->first->prev->data < el))
		{
			rule_rotate(a, a, 'a');
		}
	}
}

int	b_to_a(t_circle *a, t_circle *b, int min)
{
	t_node	*temp;
	int		i;

	while (b->first)
	{
		turn_a_to_put_el_from_b(a, b->first->data);
		rule_push(a, b, 'a');
	}
	temp = a->first;
	i = 0;
	while (temp->data != min)
	{
		i++;
		temp = temp->next;
	}
	if (i > a->size / 2)
		while (a->first->data != min)
			rule_rotate(a, b, 'a');
	else
		while (a->first->data != min)
			rule_reverse_rotate(a, b, 'a');
	return (1);
}

void	push_swap(int *buf, int count)
{
	t_circle	a;
	t_circle	b;
	t_node		*del;

	if (count == 1)
		return ;
	a = array_to_circle(buf, count);
	ft_qsort(buf, count);
	b = part_one(&a, buf[count - 1], buf[0], buf[count / 2]);
	sort_three_digit(&a);
	b_to_a(&a, &b, buf[count - 1]);
	while (a.first)
	{
		del = a.first;
		a.first->prev->next = NULL;
		a.first = a.first->next;
		free(del);
	}
}

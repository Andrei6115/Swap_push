/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 06:42:13 by calecia           #+#    #+#             */
/*   Updated: 2022/01/12 12:28:33 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "test.h"

int	sort_three_digit(t_circle *a)
{
	int		i;
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
	printf("\nmin:%d, mid:%d, max:%d", min, mid, max);
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
	int	i;

	i = 0;
}

int	b_to_a(t_circle *a, t_circle *b)
{
	
}

void	push_swap(int *buf, int count)
{
	t_circle	a;
	t_circle	b;

	a = array_to_circle(buf, count);
	printf("\na:");
	print_circle(&a);
	printf("\nb:");
	print_circle(&b);
	
	ft_qsort(buf, count);
	b = part_one(&a, buf[count - 1], buf[0], buf[count / 2]);
	sort_three_digit(&a);
	
	printf("\na:");
	print_circle(&a);
	printf("\nb:");
	print_circle(&b);
}

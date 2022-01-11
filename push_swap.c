/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 06:42:13 by calecia           #+#    #+#             */
/*   Updated: 2022/01/11 21:10:05 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_null(t_circle *circle)
{
	circle->first = NULL;
	circle->size = 0;
}

t_node	*ft_new_node(int data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		exit(2);
	new->next = NULL;
	new->prev = NULL;
	new->data = data;
	return (new);
}
#include "test.h"

void	sort_three_digit(t_circle *a)
{

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
	printf("\na:");
	print_circle(&a);
	printf("\nb:");
	print_circle(&b);
//	ft_push_node_front(take_node(&b, buf[0]), &a, 1);
//	ft_push_node_front(take_node(&b, buf[count / 2]), &a, 1);
//	ft_push_node_front(take_node(&b, buf[count - 1]), &a, 1);
//buf[0] - min, buf[count-1] - max, buf[count/2] - mid
}

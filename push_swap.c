/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrei <andrei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 06:42:13 by calecia           #+#    #+#             */
/*   Updated: 2022/01/08 07:46:58 by andrei           ###   ########.fr       */
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

void	push_swap(int buf[10000], int count)
{
	t_circle	a;
	t_circle	b;

	b = array_to_circle(buf, count);
	ft_null(&a);
	print_circle(&b);
	//ft_qsort(buf, count);
	ft_push_node_front(take_node(&b, buf[0]), &a, 1);
	ft_push_node_front(take_node(&b, buf[count / 2]), &a, 1);
	ft_push_node_front(take_node(&b, buf[count - 1]), &a, 1);
	printf("\n");
	print_circle(&a);
	printf("\n");
	print_circle(&b);
}

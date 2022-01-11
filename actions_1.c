/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 01:39:47 by calecia           #+#    #+#             */
/*   Updated: 2022/01/11 20:48:54 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_rotate(t_circle *circle)
{
	if (circle->size < 2)
		return (0);
	circle->first = circle->first->next;
	return (1);
}

int	ft_rrotate(t_circle *circle)
{
	if (circle->size < 2)
		return (0);
	circle->first = circle->first->prev;
	return (1);
}

int	ft_swap(t_circle *circle)
{
	t_node	*temp;

	if (circle->size < 2)
		return (0);
	if (circle->size == 2)
	{
		ft_rotate(circle);
		return (1);
	}
	temp = circle->first->next;
	circle->first->next = temp->next;
	temp->next->prev = circle->first;
	circle->first->prev->next = temp;
	temp->prev = circle->first->prev;
	temp->next = circle->first;
	circle->first->prev = temp;
	circle->first = temp;
	return (1);
}

void	ft_push_node_front(t_node *node, t_circle *dest, int back)
{
	if (dest->size == 0)
	{
		node->next = NULL;
		node->prev = NULL;
	}
	else if (dest->size == 1)
	{
		dest->first->next = node;
		dest->first->prev = node;
		node->next = dest->first;
		node->prev = dest->first;
	}
	else
	{
		node->next = dest->first;
		node->prev = dest->first->prev;
		dest->first->prev->next = node;
		dest->first->prev = node;
	}
	dest->first = node;
	dest->size++;
	if (back)
		ft_rotate(dest);
}

int	ft_push(t_circle *src, t_circle *dest)
{
	t_node	*temp;

	if (src->size == 0)
		return (0);
	temp = src->first;
	src->size--;
	if (src->size == 0)
	{
		src->first = NULL;
	}
	else if (src->size == 1)
	{
		src->first = src->first->next;
		src->first->next = NULL;
		src->first->prev = NULL;
	}
	else if (src->size > 2)
	{
		src->first = src->first->next;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
	ft_push_node_front(temp, dest, 0);
	return (1);
}

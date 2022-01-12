/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 06:43:26 by andrei            #+#    #+#             */
/*   Updated: 2022/01/12 11:46:51 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_node	*search_node(t_circle *circle, int data_search)
{
	t_node	*temp;
	int		i;

	temp = circle->first;
	i = 0;
	while (temp->data != data_search && i < circle->size)
	{
		temp = temp->next;
		i++;
	}
	if (i == circle->size)
		return (NULL);
	return (temp);
}

t_node	*take_node(t_circle *circle, int data_del)
{
	t_node	*ret;

	if (circle->size == 0)
		return (NULL);
	if (circle->size == 1)
	{
		ret = circle->first;
		circle->first = NULL;
	}
	if (circle->size == 2)
	{
		ret = search_node(circle, data_del);
		ret->next->next = NULL;
		ret->next->prev = NULL;
	}
	if (circle->size > 2)
	{
		ret = search_node(circle, data_del);
		ret->prev->next = ret->next;
		ret->next->prev = ret->prev;
	}
	if (ret == circle->first && circle->size > 1)
		circle->first = circle->first->next;
	circle->size--;
	return (ret);
}

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

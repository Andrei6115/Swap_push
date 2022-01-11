/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrayFunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrei <andrei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 05:47:36 by andrei            #+#    #+#             */
/*   Updated: 2022/01/08 06:36:50 by andrei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_circle	array_to_circle(int array[10000], int count)
{
	int			i;
	t_circle	a;

	i = 0;
	ft_null(&a);
	while (i < count)
	{
		ft_push_node_front(ft_new_node(array[i]), &a, 1);
		i++;
	}
	return (a);
}

void	ft_qsort(int *array, int count)
{
	int	i;
	int	j;
	int	mid;
	int	temp;

	i = 0;
	j = count - 1;
	mid = array[count / 2];
	while (i <= j)
	{
		while (array[i] > mid)
			i++;
		while (array[j] < mid)
			j--;
		if (i <= j)
		{
			temp = array[i];
			array[i++] = array[j];
			array[j--] = temp;
		}
	}
	if (j > 0)
		ft_qsort(array, j + 1);
	if (i < count)
		ft_qsort(&array[i], count - i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:28:06 by calecia           #+#    #+#             */
/*   Updated: 2022/01/14 14:54:51 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	have_duplicate(int *buf, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (buf[i] == buf[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	sorted(int *buf, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (buf[i - 1] > buf[i])
			return (0);
		i++;
	}
	return (1);
}

int	checker_buf(int *buf, int size)
{
	if (have_duplicate(buf, size))
	{
		write (STDERR_FILENO, "Error\n", 6);
		return (0);
	}
	if (sorted(buf, size))
	{
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	*buf;
	int	size;

	size = 0;
	i = 1;
	buf = malloc(sizeof(int) * (argc - 1));
	if (argc < 2)
	{
		write (STDERR_FILENO, "Error\n", 6);
		return (0);
	}
	while (i < argc)
	{
		buf[size++] = valid_int(argv[i]);
		i++;
	}
	i--;
	if (!checker_buf(buf, i))
		return (0);
	push_swap(buf, i);
	free(buf);
	return (0);
}

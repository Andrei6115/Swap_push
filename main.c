/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrei <andrei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:28:06 by calecia           #+#    #+#             */
/*   Updated: 2022/01/08 07:07:41 by andrei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "header.h"

// int	ft_isspace(char c)
// {
// 	return (c == ' ' || c == '\n' || c == '\t' || c == '\v'
// 		|| c == '\f' || c == '\r');
// }

// int	separator(char *str, int buf[10000])
// {
// 	int		i;
// 	int		size_str;
// 	int		count;
// 	char	*temp;

// 	i = 0;
// 	count = 0;
// 	while (str[i])
// 	{
// 		size_str = 0;
// 		while (ft_isspace(str[i] && str[i]))
// 			i++;
// 		while (str[i + size_str] && !ft_isscpace(str[i + size_str]))
// 		{
// 			size_str++;
// 		}
// 		if (size_str == 0)
// 			exit (2);
// 		temp = malloc(sizeof(char) * size_str);
// 		if (!temp)
// 			exit (2);
// 		ft_strlcpy(temp, &str[i], size_str);
// 		i += size_str;
// 		count++;
// 	}
// 	return (count);
// }
#include "test.h"

int	main(int argc, char **argv)
{
	int	i;
	int	buf[10000];
	int	size;

	size = 0;
	i = 1;
	while (i < argc)
	{
		buf[size++] = valid_int(argv[i]);
		printf("%d   ", valid_int(argv[i]));
		printf("%d\n", atoi(argv[i]));
		i++;
	}
	i--;
	push_swap(buf, i);
	return (0);
}

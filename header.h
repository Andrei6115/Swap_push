/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:52:57 by calecia           #+#    #+#             */
/*   Updated: 2022/01/11 17:23:40 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "libft/libft.h"

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				data;
}	t_node;

typedef struct s_circle
{
	t_node	*first;
	int		size;
}	t_circle;

int			valid_int(char *str);
void		ft_push_node_front(t_node *node, t_circle *dest, int back);
void		push_swap(int buf[10000], int count);
void		ft_null(t_circle *circle);
t_node		*ft_new_node(int data);
t_node		*search_node(t_circle *circle, int data_search);
t_node		*take_node(t_circle *circle, int data_del);
void		ft_qsort(int *array, int count);

int			ft_swap(t_circle *circle);
int			ft_rrotate(t_circle *circle);
int			ft_rotate(t_circle *circle);
int			ft_push(t_circle *src, t_circle *dest);
t_circle	array_to_circle(int array[10000], int count);

int			rule_reverse_rotate(t_circle *a, t_circle *b, char a_b_r);
int			rule_rotate(t_circle *a, t_circle *b, char a_b_r);
int			rule_push(t_circle	*a, t_circle *b, char a_b);
int			rule_swap(t_circle	*a, t_circle *b, char a_b_s);
#endif
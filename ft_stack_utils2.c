/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhonda <rhonda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 00:43:58 by rhonda            #+#    #+#             */
/*   Updated: 2024/08/21 00:43:58 by rhonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_find_index(t_stack *x, int target)
{
	int	i;

	i = 0;
	while (x->num != target)
	{
		i++;
		x = x->next;
	}
	x->index = 0; //mark the node?
	return (i);
}

int	ft_find_place_b(t_stack *b, int num_push)
{
	int		i;
	t_stack	*b_next;

	i = 1;
	if (b->num < num_push && num_push < ft_listlast(b)->num)
		i = 0;
	else if (num_push < ft_min(b) || ft_max(b) < num_push)
		i = ft_find_index(b, ft_max(b));
	else
	{
		b_next = b->next;
		while (b->num < num_push || num_push < b_next->num)	// !! (!(b->num > num_push && num_push > b_next->num))
		{
			b = b->next;
			b_next = b->next;
			i++;
		}
	}
	return (i);
}

int	ft_find_place_a(t_stack *a, int num_push)
{
	int		i;
	t_stack	*a_next;

	i = 1;
	if (num_push < a->num && ft_listlast(a)->num < num_push)
		i = 0;
	else if (num_push < ft_min(a) || ft_max(a) < num_push)
		i = ft_find_index(a, ft_min(a));
	else
	{
		a_next = a->next;
		while (num_push < a->num || a_next->num < num_push)	// !! (!(a->num < num_push && num_push < a_next->num))
		{
			a = a->next;
			a_next = a->next;
			i++;
		}
	}
	return (i);
}

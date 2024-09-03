/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checksorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhonda <rhonda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 01:24:30 by rhonda            #+#    #+#             */
/*   Updated: 2024/08/19 01:24:30 by rhonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_checksorted(t_stack *a)	// !! 返り値はbool型推奨
{
	int	i;

	i = a->num;
	while (a != NULL)
	{
		if (i > a->num)
			return (0);
		i = a->num;
		a = a->next;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhonda <rhonda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:00:22 by rhonda            #+#    #+#             */
/*   Updated: 2024/08/17 17:00:22 by rhonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_checkdup(t_stack *a)	// !! 返り値はbool型推奨
{
	t_stack	*tmp;

	while (a != NULL) {
		tmp = a->next;
		while (tmp != NULL)
		{
			if (a->num == tmp->num)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

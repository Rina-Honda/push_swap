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

#include "./ft_push_swap.h"

int	ft_checksorted(t_stack *a)
{
	t_stack *current;

	current= a;
	while (current->next)
	{
		if (current->num >current->next->num)
			return (0); //sort is false
		current =current->next;
		// a = a->next;
	}
	return (1);//sort is true
}

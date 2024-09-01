/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhonda <rhonda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 03:21:39 by rhonda            #+#    #+#             */
/*   Updated: 2024/08/19 03:21:39 by rhonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_push_swap.h"
#include <stdio.h>

void	ft_px(t_stack **y, t_stack **x, int stack, int j)
{
	printf("check_push\n");
	t_stack	*tmp;

	if (*y == NULL)
		return ;
	tmp = *x;
	*x = *y;
	*y = (*y)->next;
	(*x)->next = tmp;
	if (j == 0)
	{
		ft_putchar('p');
		ft_putchar(stack);
		ft_putchar('\n');
	}
}

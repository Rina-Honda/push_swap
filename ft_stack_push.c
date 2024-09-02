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

#include "ft_push_swap.h"

// void	ft_px(t_stack **from, t_stack **to, char stack_name, bool print_flag)	// !! 等推奨(判読性)
void	ft_px(t_stack **y, t_stack **x, int stack, int j)
{
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

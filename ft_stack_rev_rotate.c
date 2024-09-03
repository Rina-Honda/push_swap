/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rev_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhonda <rhonda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 02:45:49 by rhonda            #+#    #+#             */
/*   Updated: 2024/08/19 02:45:49 by rhonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// void	ft_rrx(t_stack **x, char stack_name, bool print_flag)	// !! 等推奨(判読性)
void	ft_rrx(t_stack **x, int stack, int j)
{
	t_stack	*last;
	t_stack	*pre_last;

	if (*x == NULL || (*x)->next == NULL)
		return ;
	last = *x;
	while (last->next != NULL)
	{
		pre_last = last;
		last = last->next;
	}
	pre_last->next = NULL;
	last->next = *x;
	*x = last;
	if (j == 0)
	{
		ft_putchar('r');
		ft_putchar('r');
		ft_putchar(stack);
		ft_putchar('\n');
	}
}

void	ft_rrr(t_stack **a, t_stack **b, int j)	// !! int j -> bool print_flag 等推奨(判読性)
{
	// if (*a == NULL || (*a)->next == NULL || *b == NULL || (*b)->next)	// !!!! (*b)->next -> (*b)->next == NULL -> 修正済み
	if (*a == NULL || (*a)->next == NULL || *b == NULL || (*b)->next == NULL)	// 追加
		return ;
	ft_rrx(a, 'a', 1);
	ft_rrx(b, 'b', 1);
	if (j == 0)
		write(1, "rrr\n", 4);
}

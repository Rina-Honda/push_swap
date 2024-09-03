/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhonda <rhonda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 01:43:29 by rhonda            #+#    #+#             */
/*   Updated: 2024/08/19 01:43:29 by rhonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// void	ft_rx(t_stack **x, char stack_name, bool print_flag)	// !! 等推奨(判読性)
void	ft_rx(t_stack **x, int stack, int j)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*x == NULL || (*x)->next == NULL)
		return ;
	tmp = *x;
	*x = (*x)->next;
	last = ft_listlast(*x);
	last->next = tmp;
	tmp->next = NULL;
	if (j == 0)
	{
		ft_putchar('r');
		ft_putchar(stack);
		ft_putchar('\n');
	}
}

void	ft_rr(t_stack **a, t_stack **b, int j)	// !! int j -> bool print_flag 等推奨(判読性)
{
	if (*a == NULL || (*a)->next == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	ft_rx(a, 'a', 1);
	ft_rx(b, 'b', 1);
	if (j == 0)
		write(1, "rr\n", 3);
}

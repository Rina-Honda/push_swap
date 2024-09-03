/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhonda <rhonda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 03:21:24 by rhonda            #+#    #+#             */
/*   Updated: 2024/08/19 03:21:24 by rhonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// void	ft_sx(t_stack **x, char stack_name, bool print_flag)	// !! 等推奨(判読性)
void	ft_sx(t_stack **x, int stack, int j)
{
	t_stack	*tmp;

	if (*x == NULL || (*x)->next == NULL)
		return ;
	tmp = *x;
	*x = (*x)->next;
	tmp->next = (*x)->next;
	(*x)->next = tmp;
	if (j == 0)
	{
		ft_putchar('s');
		ft_putchar(stack);
		ft_putchar('\n');
	}
}

void	ft_ss(t_stack **a, t_stack **b, int j)	// !! int j -> bool print_flag 等推奨(判読性
{
	if (*a == NULL || (*a)->next == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	ft_sx(a, 'a', 1);
	ft_sx(b, 'b', 1);
	if (j == 0)
		write(1, "ss\n", 3);
}

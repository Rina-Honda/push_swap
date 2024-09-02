/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhonda <rhonda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:59:57 by rhonda            #+#    #+#             */
/*   Updated: 2024/09/02 20:59:57 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// しおりさん(syonekur)監修

int    ft_min_cost(int a, int b)
{
    if (a < b)
        return (a);
    return (b);
}

void ft_rotate_type_ab(t_stack *a, t_stack *b)
{
    t_stack *current = a;

    while (current)
    {
        int cost_rarb = ft_case_rarb(a, b, current->num);
        int cost_rrarrb = ft_case_rrarrb(a, b, current->num);
        int cost_rarrb = ft_case_rarrb(a, b, current->num);
        int cost_rrarb = ft_case_rrarb(a, b, current->num);

        current->cost = ft_min_cost(ft_min_cost(cost_rarb, cost_rrarrb), ft_min_cost(cost_rarrb, cost_rrarb));

        if (current->cost == cost_rarb)
            current->type = 1;  // UP_UP		// !! # define RARB 1 的なマクロ使うと良き(判読性)
        else if (current->cost == cost_rrarrb)
            current->type = 2;  // DOWN_DOWN	// !! 同上
        else if (current->cost == cost_rarrb)
            current->type = 3;  // UP_DOWN		// !! 同上
        else
            current->type = 4;  // DOWN_UP		// !! 同上

        current = current->next;
    }
}

void ft_rotate_type_ba(t_stack *a, t_stack *b)
{
    t_stack *current = b;

    while (current)
    {
        int cost_rarb = ft_case_rarb_a(a, b, current->num);
        int cost_rrarrb = ft_case_rrarrb_a(a, b, current->num);
        int cost_rarrb = ft_case_rarrb_a(a, b, current->num);
        int cost_rrarb = ft_case_rrarb_a(a, b, current->num);

        current->cost = ft_min_cost(ft_min_cost(cost_rarb, cost_rrarrb), ft_min_cost(cost_rarrb, cost_rrarb));

        if (current->cost == cost_rarb)
            current->type = 1;  // UP_UP		// !! ft_rotate_type_abと同じくマクロ使うと良き
        else if (current->cost == cost_rrarrb)
            current->type = 2;  // DOWN_DOWN	// !! 同上
        else if (current->cost == cost_rarrb)
            current->type = 3;  // UP_DOWN		// !! 同上
        else
            current->type = 4;  // DOWN_UP		// !! 同上

        current = current->next;
    }
}
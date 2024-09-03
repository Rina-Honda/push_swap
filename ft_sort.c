/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 01:44:49 by rhonda            #+#    #+#             */
/*   Updated: 2024/09/03 01:04:12 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// しおりさん(syonekur)監修

t_stack *find_most_lowest_node(t_stack *a)
{
    t_stack *tmp = a;
    t_stack *most_lowest_node;

    most_lowest_node=a;
    while(tmp)
    {
        if(tmp->cost<most_lowest_node->cost)
            most_lowest_node=tmp;
        tmp=tmp->next;
    }
    return (most_lowest_node);
}

static void ft_sort_b_till_three(t_stack **a, t_stack **b)
{
    while (ft_listsize(*a) > 3 && !ft_checksorted(*a))
    {
        ft_rotate_type_ab(*a, *b);
		t_stack *most_lowest_node = find_most_lowest_node(*a);
		if (most_lowest_node->type == 1)		// !! ft_rotate_type_abと同じくマクロ使うと良き
            ft_apply_rarb(a, b, most_lowest_node->num, 'a');
        else if (most_lowest_node->type == 2)	// !! 同上
            ft_apply_rrarrb(a, b, most_lowest_node->num, 'a');
        else if (most_lowest_node->type == 3)	// !! 同上
            ft_apply_rarrb(a, b, most_lowest_node->num, 'a');
        else if (most_lowest_node->type == 4)	// !! 同上
            ft_apply_rrarb(a, b, most_lowest_node->num, 'a');
        else
            ft_px(a, b, 'b', 0);
    }
}

static t_stack	*ft_sort_b(t_stack **a)
{
	t_stack	*b;
	
	b = NULL;
	if (ft_listsize(*a) > 3 && !ft_checksorted(*a))
		ft_px(a, &b, 'b', 0);
	if (ft_listsize(*a) > 3 && !ft_checksorted(*a))
		ft_px(a, &b, 'b', 0);
	if (ft_listsize(*a) > 3 && !ft_checksorted(*a))
		ft_sort_b_till_three(a, &b);
	if (!ft_checksorted(*a))
		ft_sort_three(a);
	return (b);
}

void ft_sort_a(t_stack **a, t_stack **b)
{
    while (*b != NULL)
    {
        ft_rotate_type_ba(*a, *b);
		t_stack *most_lowest_node = find_most_lowest_node(*b);
        if (most_lowest_node->type == 1)		// !! ft_rotate_type_abと同じくマクロ使うと良き
            ft_apply_rarb(a, b, most_lowest_node->num, 'b');
        else if (most_lowest_node->type == 2)	// !! 同上
            ft_apply_rrarrb(a, b, most_lowest_node->num, 'b');
        else if (most_lowest_node->type == 3)	// !! 同上
            ft_apply_rarrb(a, b, most_lowest_node->num, 'b');
        else if (most_lowest_node->type == 4)	// !! 同上
            ft_apply_rrarb(a, b, most_lowest_node->num, 'b');
        else
            ft_px(b, a, 'a', 0);
	}
}

void	ft_sort(t_stack **a)
{
	t_stack	*b;
	int		i;

	b = NULL;
	if (ft_listsize(*a) == 2)
		ft_sx(a, 'a', 0);
	else
	{
		b = ft_sort_b(a);
		ft_sort_a(a, &b);
		i = ft_find_index(*a, ft_min(*a));
		if (i < (ft_listsize(*a) - i))
		{
			while ((*a)->num != ft_min(*a))
				ft_rx(a, 'a', 0);
		}
		else
		{
			while ((*a)->num != ft_min(*a))
				ft_rrx(a, 'a', 0);
		}
	}
}

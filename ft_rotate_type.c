/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_rotate_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhonda <rhonda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 00:17:14 by rhonda            #+#    #+#             */
/*   Updated: 2024/08/21 00:17:14 by rhonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// int	ft_rotate_type_ab(t_stack *a, t_stack *b)
// {
// 	int		i;
// 	t_stack	*tmp;

// 	tmp = a;
// 	i = ft_case_rrarrb(a, b, a->num);
// 	while (tmp != NULL) //より回転コストが少ない択にする
// 	{
// 		if (i > ft_case_rarb(a, b, tmp->num)) 
// 			i = ft_case_rarb(a, b, tmp->num);
// 		if (i > ft_case_rrarrb(a, b, tmp->num))
// 			i = ft_case_rrarrb(a, b, tmp->num);
// 		if (i > ft_case_rarrb(a, b, tmp->num))
// 			i = ft_case_rarrb(a, b, tmp->num);
// 		if (i > ft_case_rrarb(a, b, tmp->num))
// 			i = ft_case_rrarb(a, b, tmp->num);
// 		tmp = tmp->next;
// 	}
// 	return (i);
// }
// // #include <stdio.h>
// int	ft_rotate_type_ba(t_stack *a, t_stack *b)
// {
// 	int		i;
// 	t_stack	*tmp;

// 	tmp = b;
// 	i = ft_case_rrarrb_a(a, b, b->num);
// 	// printf("rotate_type_ba: %d\n", i);
// 	while (tmp != NULL)
// 	{
// 		if (i > ft_case_rarb_a(a, b, tmp->num))
// 			i = ft_case_rarb_a(a, b, tmp->num);
// 		if (i > ft_case_rrarrb_a(a, b, tmp->num))
// 			i = ft_case_rrarrb_a(a, b, tmp->num);
// 		if (i > ft_case_rarrb_a(a, b, tmp->num))
// 			i = ft_case_rarrb_a(a, b, tmp->num);
// 		if (i > ft_case_rrarb_a(a, b, tmp->num))
// 			i = ft_case_rrarb_a(a, b, tmp->num);
// 		tmp = tmp->next;
// 	}
// 	// printf("rotate_type_ba: %d\n", i);
// 	return (i);
// }

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

t_stack *ft_rotate_type_ab(t_stack *a, t_stack *b)
{
    t_stack *tmp = a;
    int cost;
    t_stack *most_lowest_node;

    most_lowest_node=a;
    while (tmp != NULL)
    {
        most_lowest_node->cost= ft_case_rarb(a, b, tmp->num);
        if (cost <most_lowest_node->cost)
        {
            most_lowest_node->type = 1;
            most_lowest_node->cost = cost;
        }

        cost = ft_case_rrarrb(a, b, tmp->num);
        if (cost <most_lowest_node->cost)
        {
            most_lowest_node->type = 2;
            most_lowest_node->cost = cost;
        }

        cost = ft_case_rarrb(a, b, tmp->num);
        if (cost <most_lowest_node->cost)
        {
            most_lowest_node->type = 3;
            most_lowest_node->cost = cost;
        }

        cost = ft_case_rrarb(a, b, tmp->num);
        if (cost <most_lowest_node->cost)
        {
            most_lowest_node->type = 4;
            most_lowest_node->cost = cost;
        }

        tmp = tmp->next;
    }
    most_lowest_node=find_most_lowest_node(a);

    return (most_lowest_node);
}
//関数は回転コストの値を返していますが、呼び出し元では回転タイプとして扱っています。
//最小コトを持つ回転タイプの情報が失われています。

// #include <stdio.h>
t_stack *ft_rotate_type_ba(t_stack *a, t_stack *b)
{
   t_stack *most_lowest_node; // 初期値を設定
    t_stack *tmp = b;
    int cost;

    most_lowest_node=b;
    while (tmp != NULL)
    {
        cost = ft_case_rarb_a(a, b, tmp->num);
        if (cost < most_lowest_node->cost)
        {
            most_lowest_node->type = 1;
            most_lowest_node->cost = cost;
        }

        cost = ft_case_rrarrb_a(a, b, tmp->num);
        if (cost < most_lowest_node->cost)
        {
            most_lowest_node->type = 2;
            most_lowest_node->cost = cost;
        }

        cost = ft_case_rarrb_a(a, b, tmp->num);
        if (cost < most_lowest_node->cost)
        {
            most_lowest_node->type = 3;
            most_lowest_node->cost = cost;
        }

        cost = ft_case_rrarb_a(a, b, tmp->num);
        if (cost < most_lowest_node->cost)
        {
            most_lowest_node->type = 4;
            most_lowest_node->cost = cost;
        }

        tmp = tmp->next;
    }

    return most_lowest_node;
}

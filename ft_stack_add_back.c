/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhonda <rhonda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:49:01 by rhonda            #+#    #+#             */
/*   Updated: 2024/08/19 00:49:01 by rhonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_push_swap.h"

t_stack *ft_listlast(t_stack *list)
{
    while (list != NULL)
    {
        if (list->next == NULL)
            return (list);
        list = list->next;
    }
    return (list);
}

void    ft_stack_add_back(t_stack **stack, t_stack *node)
{
    if (stack == NULL)
        return ;
    if (*stack == NULL)
        *stack = node;
    else
        (ft_listlast(*stack))->next = node;
}

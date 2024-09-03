/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:57:27 by rhonda            #+#    #+#             */
/*   Updated: 2024/09/03 01:03:50 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*ft_new_node(int num)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		ft_error();
		// !!!! "Error\n"を出力しているだけで先に進んでしまうので不十分 -> 修正済み
	else	// 追加
	{
		node->num = num;	// !!!! malloc失敗時に NULL->num にアクセスしてしまうのでsegv -> 修正済み
		node->next = NULL;	// !!!! 同上 -> 修正済み
	}
	return (node);
}

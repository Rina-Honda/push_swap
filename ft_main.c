/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhonda <rhonda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:55:15 by rhonda            #+#    #+#             */
/*   Updated: 2024/07/25 04:55:15 by rhonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = ft_parse_args(argc, argv);
	if (a == NULL || ft_checkdup(a))
	{
		ft_free(&a);
		ft_error();
		return (0);	// !!!! エラー終了なら return (1); にすべき -> 未修正
	}
	if (!ft_checksorted(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}

// !! leaksチェック用(SANITIZE使用時はコメントアウト)
// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }
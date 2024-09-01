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

#include "./ft_push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	**a;

	a = ft_parse_args(argc, argv);
	if (a == NULL || ft_checkdup((a)))
	{
		ft_free(a);
		ft_error();
		return (0);
	}
	// printf("check\n");

	// int c = ft_checksorted(a);
	// printf("%d\n", c);

	if (!ft_checksorted(a))
		ft_sort(a);
	// printf("check2\n");
	// printf("=======\n");
	// while (a != NULL)
	// {
	//     printf("%ld\n", a->num);
	//     a = a->next;
	// }

	ft_free(a);
	return (0);
}

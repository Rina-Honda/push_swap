/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:33:57 by rhonda            #+#    #+#             */
/*   Updated: 2024/09/03 01:03:50 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_atoi(const char *str)
{
	int			mod;
	long long	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\f' || *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0')
	{
		i = i * 10 + (*str - '0');
		str++;
	}
	if ((i * mod) < INT_MIN || INT_MAX < (i * mod))
		ft_error();
		// !!!! intの範囲を超えた場合でも"Error\n"と出力しているだけなので -> 未修正
		// !!!! return (i * mod); でオーバー・アンダーフローした値がそのまま返されている(エラー処理が不十分) -> 未修正
	return (i * mod);
}

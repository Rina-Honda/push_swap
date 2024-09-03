/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 05:23:23 by rhonda            #+#    #+#             */
/*   Updated: 2024/09/03 01:04:12 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_isdigit(char *str)	// !! 返り値はbool型推奨
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') 
		&& ('0' <= str[i + 1] && str[i + 1] <= '9'))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || '9' < str[i])
			return (0);
		i++;
	}
	return (1);
}

static	t_stack *ft_new_stack_variable_args(char **argv)
{
	t_stack	*a;
	t_stack	*node;
	int		i;

	a = NULL;
	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_isdigit(argv[i]))
		{
			node = ft_new_node(ft_atoi(argv[i]));	// !!!! ft_atoi失敗時の処理不足 -> 未修正
			// !!!! ft_new_node失敗時の処理不足 -> 修正済み
			if (node == NULL)	// 追加
			{
				ft_free(&a);	// 追加
				return (NULL);	// 追加
			}
			ft_stack_add_back(&a, node);
			// !!!! ft_stack_add_backの返り値がないので、nodeがNULLの場合(ft_new_node失敗時)を検知できていない -> 修正済み
			// !!!! ft_stack_add_back呼び出し前にft_new_nodeのエラー処理を行うのであれば不要 -> 修正済み
			i++;
		}
		else
		{
			// !!!! aのfree漏れ -> 修正済み
			ft_free(&a);	// 追加
			return (NULL);
		}
	}
	return (a);
}

void	ft_free_double_ptr(char **ptr)
{
	char	*tmp;

	if (ptr == NULL)
		return ;
	while (*ptr != NULL)
	{
		tmp = *ptr;
		ptr++;
		free(tmp);
	}
	*ptr = NULL;
	// !! ここでptrをfreeすれば良いのでは
}

static	t_stack *ft_new_stack_quote(char *str)
{
	t_stack	*a;
	char	**splited;
	int		i;
	t_stack	*node;

	a = NULL;
	splited = ft_split(str, ' ');
	// !!!! ft_split失敗時の処理不足 -> 未修正
	// !! そもそもft_splitしたら、splitedをft_new_stack_variable_argsに渡せば良いのでは
	i = 0;
	while (splited[i] != NULL)
	{
		if (ft_isdigit(splited[i]))
		{
			node = ft_new_node(ft_atoi(splited[i]));	// !!!! ft_atoi失敗時の処理不足 -> 未修正
			// !!!! ft_new_node失敗時の処理不足 -> 修正済み
			if (node == NULL)	// 追加
				break ;			// 追加
			ft_stack_add_back(&a, node);
			// !!!! ft_stack_add_backの返り値がないので、nodeがNULLの場合(ft_new_node失敗時)を検知できていない -> 修正済み
			// !!!! ft_stack_add_back呼び出し前にft_new_nodeのエラー処理を行うのであれば不要 -> 修正済み
			i++;
		}
		else
		{
			// !!!! splitedのfree漏れ -> 修正済み
			ft_free_double_ptr(splited);	// 追加
			free(splited);					// 追加
			ft_free(&a);					// 追加
			return (NULL);
		}
	}
	ft_free_double_ptr(splited);
	free(splited);	// !! splitedはft_free_double_ptr内でfreeすれば良いのでは
	if (node == NULL)
	{
		ft_free(&a);
		return (NULL);
	}
	return (a);
}

t_stack	*ft_parse_args(int argc, char **argv)
{
	t_stack *a;

	a = NULL;
	if (argc == 2 && *argv[1] != '\0')
		a = ft_new_stack_quote(argv[1]);
	else if (argc > 2)
		a = ft_new_stack_variable_args(argv);
	return (a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhonda <rhonda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 05:23:23 by rhonda            #+#    #+#             */
/*   Updated: 2024/09/01 20:29:18 by rhonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_push_swap.h"

static int	ft_isdigit(char *str)
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

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_isdigit(argv[i]))
		{
			node = ft_new_node(ft_atoi(argv[i]));
			ft_stack_add_back(&a, node);
			i++;
		}
		else
		{
			write(2, "Error\n", 6);
			ft_free(&a);
			exit(1);
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
}

static	t_stack *ft_new_stack_quote(char *str)
{
	t_stack	*a;
	char	**splited;
	int		i;
	t_stack	*node;

	a = NULL;
	splited = ft_split(str, ' ');
	i = 0;
	while (splited[i] != NULL)
	{
		if (ft_isdigit(splited[i]))
		{
			node = ft_new_node(ft_atoi(splited[i]));
			ft_stack_add_back(a, node);
			i++;
		}
		else
		{
			write(2, "Error\n", 6);
			ft_free(&a);
			exit(1);
		}
	}
	ft_free_double_ptr(splited);
	free(splited);
	return (a);
}

t_stack	**ft_parse_args(int argc, char **argv)
{
	t_stack *a;

	a = NULL;
	if (argc == 2 && *argv[1] != '\0')
		a = ft_new_stack_quote(argv[1]);
	else if (argc > 2)
		a = ft_new_stack_variable_args(argv);
	return (&(a));
}

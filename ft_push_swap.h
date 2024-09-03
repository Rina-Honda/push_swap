/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:55:32 by rhonda            #+#    #+#             */
/*   Updated: 2024/09/03 01:04:12 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

//include
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
// # include <stdbool.h> // !! bool型を使う場合
# include <stdio.h>	// debug用

//define
// # define RARB 1		// !! ft_rotate_type.c, ft_sort.c内で使用する場合
// # define RRARRB 2	// !! 同上
// # define RARRB 3		// !! 同上
// # define RRARB 4		// !! 同上

//typedef  

//struct
typedef struct s_stack
{
	long			num;
	long			index;
	int				cost;	// 追加
	int				type;	// 追加
	struct s_stack *next;
	struct s_stack *prev;	// !!! 未使用では
}	t_stack;

//function
void	ft_error(void);
void	ft_free(t_stack **list);
int		ft_checkdup(t_stack *a);
int		ft_checksorted(t_stack *a);
t_stack	*ft_new_node(int num);
t_stack	*ft_parse_args(int argc, char **argv);
void	ft_stack_add_back(t_stack **stack, t_stack *new_node);

void	ft_sort(t_stack **a);
void	ft_sort_three(t_stack **a);
void	ft_rotate_type_ab(t_stack *a, t_stack *b);	// 修正
void	ft_rotate_type_ba(t_stack *a, t_stack *b);	// 修正

int		ft_case_rarb(t_stack *a, t_stack *b, int target);
int		ft_case_rrarrb(t_stack *a, t_stack *b, int target);
int		ft_case_rrarb(t_stack *a, t_stack *b, int target);
int		ft_case_rarrb(t_stack *a, t_stack *b, int target);
int		ft_apply_rarb(t_stack **a, t_stack **b, int target, char c);
int		ft_apply_rrarrb(t_stack **a, t_stack **b, int target, char c);
int		ft_apply_rrarb(t_stack **a, t_stack **b, int target, char c);
int		ft_apply_rarrb(t_stack **a, t_stack **b, int target, char c);

int		ft_case_rarb_a(t_stack *a, t_stack *b, int target);
int		ft_case_rrarrb_a(t_stack *a, t_stack *b, int target);
int		ft_case_rarrb_a(t_stack *a, t_stack *b, int target);
int		ft_case_rrarb_a(t_stack *a, t_stack *b, int target);

int		ft_find_index(t_stack *x, int target);
int		ft_find_place_b(t_stack *b, int num_push);
int		ft_find_place_a(t_stack *a, int num_push);

void	ft_px(t_stack **y, t_stack **x, int stack, int j);
void	ft_sx(t_stack **x, int stack, int j);
void	ft_ss(t_stack **a, t_stack **b, int j);
void	ft_rx(t_stack **x, int stack, int j);
void	ft_rr(t_stack **a, t_stack **b, int j);
void	ft_rrx(t_stack **x, int stack, int j);
void	ft_rrr(t_stack **a, t_stack **b, int j);

void	ft_putchar(int c);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
t_stack	*ft_listlast(t_stack *list);
int		ft_listsize(t_stack *list);
int		ft_min(t_stack *a);
int		ft_max(t_stack *a);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhonda <rhonda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:55:32 by rhonda            #+#    #+#             */
/*   Updated: 2024/09/01 20:24:57 by rhonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

//include
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>

//define

//typedef  

//struct
typedef struct s_stack
{
	long			num;
	struct s_stack *next;
    int type;  // 回転タイプ（1: rarb, 2: rrarrb, 3: rarrb, 4: rrarb）
    int cost;  // 回転コスト
}	t_stack;


//function
void	ft_error(void);
void	ft_free(t_stack **list);
int		ft_checkdup(t_stack **a);
int		ft_checksorted(t_stack **a);
t_stack	*ft_new_node(int num);
t_stack	**ft_parse_args(int argc, char **argv);
void	ft_stack_add_back(t_stack **stack, t_stack *new_node);

void	ft_sort(t_stack **a);
void	ft_sort_three(t_stack **a);
// int		ft_rotate_type_ab(t_stack *a, t_stack *b);
// int		ft_rotate_type_ba(t_stack *a, t_stack *b);
t_stack *ft_rotate_type_ab(t_stack *a, t_stack *b);
t_stack *ft_rotate_type_ba(t_stack *a, t_stack *b);

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

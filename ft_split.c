/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:51:51 by rhonda            #+#    #+#             */
/*   Updated: 2024/09/03 01:04:12 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	count_words(const char *str, char c)
{
	int	i;	// !! i -> count 等推奨(判読性)
	int	trigger;	// !! bool型推奨

	i = 0;
	trigger = 0;
	while (*str != '\0')
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (finish - start + 1));
	// !!!! malloc失敗時の処理不足 -> 修正済み
	if (word == NULL)	// 追加
		return (NULL);	// 追加
	while (start < finish)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**splited;

	// splited = (char **)malloc(sizeof(char *) * count_words(s, c) + 1);	// !!!! sizeof(char *) * (count_words(s, c) + 1)が正しい
	splited = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));	// 追加
	if (s == NULL || splited == NULL)	// !! sのNULLチェックをするなら、malloc前にするべき(今回はそもそもしなくても良いが)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		if (s[i] == c || (i == ft_strlen(s) && index >= 0))
		{
			// !!! 先頭が' 'または' 'が連続する時、indexが-1のままword_dupに渡される -> 未修正
			// !!! そのため、 ./push_swap " 1 2 3" や ./push_swap "1 2  3" でエラーになる -> 未修正
			// !!! 上記のパターンに対応しないという選択肢はありだが、segvや異常終了しないように修正する必要はある
			splited[j] = word_dup(s, index, i);
			// !!!! word_dup失敗時の処理不足 -> 修正済み
			if (splited[j++] == NULL)	// 追加
			{
				while (j > 0)			// 追加
					free(splited[--j]);	// 追加
				free(splited);			// 追加
				return (NULL);			// 追加
			}
			index = -1;
		}
		i++;
	}
	splited[j] = 0;	// !! 個人的には0よりNULLの方が判読性◯
	return (splited);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:20:10 by alkhbiri          #+#    #+#             */
/*   Updated: 2024/11/16 21:20:20 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_w(const char *s, char c)
{
	int	count;
	int	in_w;

	count = 0;
	in_w = 0;
	while (*s)
	{
		if (*s != c && !in_w)
		{
			in_w = 1;
			count ++;
		}
		else if (*s == c)
			in_w = 0;
		s++;
	}
	return (count);
}

static char	*word_dup(const char *s, size_t start, size_t end)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = malloc(end - start + 1);
	if (!dup)
		return (NULL);
	while (start < end)
		dup[i++] = s[start++];
	dup[i] = '\0';
	return (dup);
}

static void	ft_free(char **split, int j)
{
	while (j >= 0)
		free(split[j--]);
	free(split);
}

static int	test(char **split, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			split[j] = word_dup(s, start, i);
			if (!split[j])
			{
				ft_free(split, j);
				return (0);
			}
			j++;
		}
		if (s[i])
			i++;
	}
	return (split[j] = NULL, 1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		flag;

	if (!s)
		return (NULL);
	split = (char **)malloc((count_w (s, c) + 1) * sizeof (char *));
	if (!split)
		return (NULL);
	flag = test(split, s, c);
	if (flag == 0)
		return (NULL);
	return (split);
}

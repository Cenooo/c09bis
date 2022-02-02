/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:29:51 by swaegene          #+#    #+#             */
/*   Updated: 2022/02/01 10:59:38 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *str, int n)
{
	int		i;
	char	*result;

	i = 0;
	result = malloc(sizeof(char) * (n + 1));
	while (i < n)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *sep)
{
	int	i;
	int	words;

	i = 0;
	words = 1;
	while (str[i])
	{
		if (!is_sep(str[i], sep) && is_sep(str[i - 1], sep))
			words++;
		i++;
	}
	return (words);
}

char	**ft_split(char *str, char *charset)
{
	int		start;
	int		end;
	char	**result;
	int		t_index;

	t_index = 0;
	result = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	start = 0;
	while (str[start])
	{
		end = start;
		while (str[end] && !is_sep(str[end], charset))
			end++;
		if (end != start)
		{
			result[t_index] = ft_strncpy(&str[start], end - start);
			t_index++;
			start = end;
		}
		else
			start++;
	}
	result[t_index] = 0;
	return (result);
}
/*#include <stdio.h>
int	main(void)
{
	int		i;
	char	**r;

	i = 0;
	r = ft_split("asdfadsf 22 33 44 ", "a ");
	while (r[i])
	{
		printf("%s\n", r[i]);
		i++;
	}
}*/

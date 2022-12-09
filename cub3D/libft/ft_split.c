/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:09:50 by sfathima          #+#    #+#             */
/*   Updated: 2022/08/24 12:12:11 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		count++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (count);
}

static int	ft_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	*ft_strndup(char const *s, int len)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc(sizeof (char) * (len + 1));
	while (i < len)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static void	ft_free(char **s, int i)
{
	if (!s)
	{
		while (i-- != 0)
			free(s[i]);
		free(s);
	}
}

char	**ft_split(char const *s, char c)
{
	int		word_len;
	int		word_count;
	char	**result;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	result = (char **)malloc(sizeof (char *) * (word_count + 1));
	if (result == NULL)
		return (NULL);
	while (i < word_count)
	{
		while (*s && *s == c)
			s++;
		word_len = ft_word_len(s, c);
		result[i] = ft_strndup(s, word_len);
		ft_free(result, i - 1);
		s = s + word_len;
		i++;
	}
	result[word_count] = 0;
	return (result);
}

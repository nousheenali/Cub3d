/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:51:07 by nali              #+#    #+#             */
/*   Updated: 2021/12/10 15:51:07 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_findlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*str_concat(char *s1, const char *s2)
{
	int		l1;
	int		l2;
	char	*str;
	int		i;
	int		j;

	l1 = ft_findlen(s1);
	l2 = ft_findlen(s2);
	str = (char *)malloc((l1 + l2 + 1) * sizeof(char));
	i = 0;
	if (l1 > 0)
	{	
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	free((void *)s2);
	return (str);
}

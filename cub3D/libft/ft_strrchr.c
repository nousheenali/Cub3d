/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42abudhabi      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:29:50 by sfathima          #+#    #+#             */
/*   Updated: 2021/10/12 14:37:34 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ch;
	int		flag;

	flag = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			ch = (char *)s;
			flag = 1;
		}
		s++;
	}
	if (*s == '\0' && *s == (char)c)
	{
		ch = (char *)s;
		return (ch);
	}
	if (flag == 0)
		return (NULL);
	return (ch);
}

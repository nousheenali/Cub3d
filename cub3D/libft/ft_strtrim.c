/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42abudhabi      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 10:49:09 by sfathima          #+#    #+#             */
/*   Updated: 2021/10/10 12:51:20 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*str;

	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1) != 0)
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && *s1 && ft_strchr(set, s1[len - 1]) != 0)
		len--;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	ft_memcpy(str, s1, len);
	str[len] = '\0';
	return (str);
}

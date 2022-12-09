/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:01:25 by sfathima          #+#    #+#             */
/*   Updated: 2022/03/23 12:31:34 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	flag;
	int	n_len;

	i = 0;
	flag = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	n_len = ft_strlen(needle);
	while (*haystack && len-- >= (size_t)n_len)
	{
		i = 0;
		while (needle[i] && (haystack[i] == needle[i]) && len >= 0)
		{
			if (needle[i + 1] == '\0')
				flag = 1;
			i++;
		}
		if (flag == 1)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}

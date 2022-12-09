/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42abudhabi      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:34:27 by sfathima          #+#    #+#             */
/*   Updated: 2021/10/10 10:11:42 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		len;

	str = (char *)s1;
	len = ft_strlen(s1);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	ft_memcpy(str, s1, len);
	str[len] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42abudhabi      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:01:21 by sfathima          #+#    #+#             */
/*   Updated: 2021/09/30 14:56:50 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*t_dst;
	char	*t_src;

	if (!dst && !src)
		return (0);
	if (dst < src)
	{
		t_dst = (char *)dst;
		t_src = (char *)src;
		while (n-- > 0)
			*t_dst++ = *t_src++;
	}
	else
	{
		t_dst = (char *)dst + n - 1;
		t_src = (char *)src + n - 1;
		while (n-- > 0)
		{
			*t_dst = *t_src;
			--t_dst;
			--t_src;
		}
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42abudhabi      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:19:25 by sfathima          #+#    #+#             */
/*   Updated: 2021/09/30 14:56:22 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*t_dst;
	char	*t_src;

	if (!dst && !src)
		return (0);
	t_dst = (char *)dst;
	t_src = (char *)src;
	while (n > 0)
	{
		*t_dst = *t_src;
		t_dst++;
		t_src++;
		n--;
	}
	return (dst);
}

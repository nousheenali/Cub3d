/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42abudhabi      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:41:15 by sfathima          #+#    #+#             */
/*   Updated: 2021/10/12 13:51:35 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ch;

	ch = (char *) s;
	while (n > 0)
	{
		if (*ch == (char)c)
			return (ch);
		n--;
		ch++;
	}
	return (0);
}

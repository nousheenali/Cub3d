/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42abudhabi      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:13:30 by sfathima          #+#    #+#             */
/*   Updated: 2021/10/03 16:16:13 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*t_s1;
	char	*t_s2;

	t_s1 = (char *)s1;
	t_s2 = (char *)s2;
	while (n > 0)
	{
		if (*t_s1 != *t_s2)
			return ((unsigned char)*t_s1 - (unsigned char)*t_s2);
		t_s1++;
		t_s2++;
		n--;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42abudhabi      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:31:55 by sfathima          #+#    #+#             */
/*   Updated: 2021/10/12 11:32:29 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigit(long n, int sign)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n = n / 10;
		len++;
	}
	if (sign == -1)
		len++;
	return (len);
}

static void	ft_writenbr(char *str, long n, int sign)
{
	*str = '\0';
	*--str = (n % 10) + '0';
	n = n / 10;
	while (n > 0)
	{
		*--str = (n % 10) + '0';
		n = n / 10;
	}
	if (sign == -1)
		*--str = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nbr;
	int		sign;

	sign = 1;
	if (n < 0)
	{
		nbr = (long)n * -1;
		sign = -1;
	}
	else
		nbr = n;
	len = ft_countdigit(nbr, sign);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	ft_writenbr(str + len, nbr, sign);
	return (str);
}

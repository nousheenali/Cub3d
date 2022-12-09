/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:45:02 by sfathima          #+#    #+#             */
/*   Updated: 2022/03/16 11:35:39 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line(int fd, char *buf, char *ln, int *flag)
{
	int	i;
	int	rd;

	rd = 1;
	i = 0;
	while (rd > 0 && i < BUFFER_SIZE)
	{
		rd = read(fd, buf + i, 1);
		if (rd == -1)
		{
			free(buf);
			free(ln);
			return (1);
		}
		if (!rd || buf[i++] == '\n')
		{
			*flag = 0;
			break ;
		}
	}
	buf[i] = '\0';
	return (0);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*buf[1024];
	int			flag;

	flag = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf[fd] = malloc(BUFFER_SIZE + 1);
	if (!buf[fd])
		return (NULL);
	str = malloc(1);
	while (flag != 0)
	{
		if (get_line(fd, buf[fd], str, &flag))
			return (NULL);
		if (!ft_strlen(str) && !ft_strlen(buf[fd]))
		{
			free(str);
			str = NULL;
		}
		str = ft_strjoin(str, buf[fd]);
	}
	free (buf[fd]);
	return (str);
}

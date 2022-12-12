/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 09:04:22 by nali              #+#    #+#             */
/*   Updated: 2021/12/12 09:04:22 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_output_string(char *str, int *bytesread, int *i, char *output)
{
	int	j;
	int	b;

	j = 0;
	b = ft_findlen(str);
	while (str[j] != '\n' && j < b)
		j++;
	if (str[j] == '\n')
		j++;
	*bytesread = b;
	*i = j;
	output = (char *)malloc((j + 1) * sizeof(char));
	if (!output)
		return (NULL);
	ft_strlcpy(output, str, j + 1);
	return (output);
}

char	*read_buffer(int fd, int *flag)
{
	char	*buf;
	int		bytesread;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	bytesread = read(fd, buf, BUFFER_SIZE);
	if (bytesread > 0)
	{
		if (bytesread != BUFFER_SIZE)
			*flag = 1;
		buf[bytesread] = '\0';
		return (buf);
	}
	*flag = 1;
	free(buf);
	return (NULL);
}

char	*read_till_newline(int fd, char *str)
{
	char		*buffer;
	static int	flag;

	flag = 0;
	buffer = read_buffer(fd, &flag);
	if (buffer != NULL)
	{
		if (str == NULL)
			str = buffer;
		else
			str = str_concat(str, buffer);
	}
	if (str != NULL)
	{
		while (ft_strchr(str, '\n') == NULL && flag == 0)
		{
			buffer = read_buffer(fd, &flag);
			if (buffer != NULL)
				str = str_concat(str, buffer);
			else
				break ;
		}
	}
	return (str);
}

char	*get_next_line(int fd)
{	
	char		*str;
	int			bytesread;
	int			i;
	char		*output;
	static char	*remaining;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = remaining;
	output = NULL;
	str = read_till_newline(fd, str);
	if (str == NULL)
		return (NULL);
	output = get_output_string(str, &bytesread, &i, output);
	if (bytesread > i)
	{
		remaining = (char *)malloc((bytesread - i + 1) * sizeof(char));
		if (!remaining)
			return (NULL);
		ft_strlcpy(remaining, &str[i], bytesread - i + 1);
	}
	else
		remaining = NULL;
	free(str);
	return (output);
}

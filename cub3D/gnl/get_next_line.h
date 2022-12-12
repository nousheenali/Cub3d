/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:52:44 by nali              #+#    #+#             */
/*   Updated: 2021/12/10 15:52:44 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1
# endif

# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

char			*get_next_line(int fd);
int				ft_findlen(const char *s);
// unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int dstsize);
// char			*ft_strchr(char *str, int c);
char			*str_concat(char *s1, const char *s2);

#endif
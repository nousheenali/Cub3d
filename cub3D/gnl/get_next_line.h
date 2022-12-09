/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:31:56 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/06 15:22:54 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdlib.h>
# include<unistd.h>
# include<fcntl.h>
# include<stdio.h>
# include "../libft/libft.h"
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
//zvoid	*ft_memcpy(void *dst, const void *restrict src, size_t n);

#endif
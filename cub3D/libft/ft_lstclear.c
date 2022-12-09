/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42abudhabi      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:36:37 by sfathima          #+#    #+#             */
/*   Updated: 2021/10/07 15:46:43 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nxt_lst;

	while (*lst)
	{
		del((*lst)->content);
		nxt_lst = *lst;
		*lst = nxt_lst->next;
		free(nxt_lst);
	}
	*lst = NULL;
}

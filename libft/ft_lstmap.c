/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 01:31:03 by okunoitsuki       #+#    #+#             */
/*   Updated: 2025/05/09 17:40:41 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tmpnode;
	void	*content;

	if (!lst | !f | !del)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		content = f(lst->content);
		tmpnode = ft_lstnew(content);
		if (!tmpnode)
		{
			del(content);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, tmpnode);
		lst = lst->next;
	}
	return (newlst);
}

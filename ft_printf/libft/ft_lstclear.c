/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 16:43:34 by llinda            #+#    #+#             */
/*   Updated: 2026/06/29 20:49:18 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	next = NULL;
	if (!lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}

/* int	main(void)
{
	t_list *lst = ft_lstnew(ft_strdup("World"));
//	t_list *lst = NULL;
	t_list *node1 = ft_lstnew(ft_strdup("Hello"));
	t_list *node3 = ft_lstnew(ft_strdup("!"));

	ft_lstadd_front(&lst, node1);
	ft_lstadd_back(&lst, node3);
	ft_lstclear(&lst, free);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 21:48:50 by llinda            #+#    #+#             */
/*   Updated: 2026/06/29 20:10:02 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/* int	main(void)
{
	t_list *lst = ft_lstnew(ft_strdup("World"));
//	t_list *lst = NULL;
	t_list *node1 = ft_lstnew(ft_strdup("Hello"));
	t_list *node3 = ft_lstnew(ft_strdup("!"));

	ft_lstadd_front(&lst, node1);
	ft_lstadd_back(&lst, node3);
	ft_lstdelone(lst, free);
} */

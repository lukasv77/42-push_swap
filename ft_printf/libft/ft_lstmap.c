/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 21:39:24 by llinda            #+#    #+#             */
/*   Updated: 2026/06/30 11:19:36 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_lst;
	void	*new_cntnt;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_cntnt = f(lst->content);
		if (!new_cntnt)
			return (ft_lstclear(&new_lst, del), NULL);
		new_node = ft_lstnew(new_cntnt);
		if (!new_node)
			return (del(new_cntnt), ft_lstclear(&new_lst, del), NULL);
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

/* static void	*putH(void *content)
{
	char	*new_content;

	new_content = ft_calloc(2, sizeof(char));
	*new_content = ((char *)content)[0];
	return (new_content);
}

int	main(void)
{
	t_list *lst = ft_lstnew(ft_strdup("World"));
//	t_list *lst = NULL;
	t_list *node1 = ft_lstnew(ft_strdup("Hello"));
	t_list *node3 = ft_lstnew(ft_strdup("!"));
	t_list	*new_lst;
	t_list	*tmp;

	ft_lstadd_front(&lst, node1);
	ft_lstadd_back(&lst, node3);
	new_lst = ft_lstmap(lst, putH, free);
	tmp = lst;
	printf ("lst - number of nodes: %d\n", ft_lstsize(lst));
	while (tmp)
	{
		printf ("Content: %s | ", (char *) tmp->content);
		tmp = tmp->next;
	}
	printf ("\n");
	tmp = new_lst;
	printf ("new_lst - number of nodes: %d\n", ft_lstsize(new_lst));
	while (tmp)
	{
		printf ("Content: %s | ", (char *) tmp->content);
		tmp = tmp->next;
	}
	printf ("\n");
	ft_lstclear(&lst, free);
	ft_lstclear(&new_lst, free);
} */
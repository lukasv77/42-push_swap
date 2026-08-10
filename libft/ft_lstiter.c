/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 18:08:37 by llinda            #+#    #+#             */
/*   Updated: 2026/06/30 11:23:18 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* static void	putH(void *content)
{
	((char *) content)[0] = 'H';
}

int	main(void)
{
	t_list *lst = ft_lstnew(ft_strdup("World"));
//	t_list *lst = NULL;
	t_list *node1 = ft_lstnew(ft_strdup("Hello"));
	t_list *node3 = ft_lstnew(ft_strdup("!"));

	ft_lstadd_front(&lst, node1);
	ft_lstadd_back(&lst, node3);
	ft_lstiter(lst, putH);
	printf ("Number of nodes: %d\n", ft_lstsize(lst));
	while (lst)
	{
		printf ("Content: %s | ", (char *) lst->content);
		lst = lst->next;
	}
} */

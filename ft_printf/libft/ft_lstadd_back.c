/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 20:52:00 by llinda            #+#    #+#             */
/*   Updated: 2026/06/27 21:46:42 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

/* int	main(void)
{
	t_list *lst = ft_lstnew((char *) "World");
//	t_list *lst = NULL;
	t_list *node3 = ft_lstnew((char *) "!");

	ft_lstadd_back(&lst, node3);
	while (lst)
	{
		printf ("%s", (char *) lst->content);
		lst = lst->next;
	}
} */
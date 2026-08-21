/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:23:24 by llinda            #+#    #+#             */
/*   Updated: 2026/06/27 20:25:37 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/* int	main(void)
{
	t_list *lst = ft_lstnew((char *) "World");
	t_list *newnode = ft_lstnew((char *) "Hello");

	ft_lstadd_front(&lst, newnode);
	while (lst)
	{
		printf ("%s", (char *) lst->content);
		lst = lst->next;
	}
} */
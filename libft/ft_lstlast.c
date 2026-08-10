/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 20:34:48 by llinda            #+#    #+#             */
/*   Updated: 2026/06/27 21:33:09 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* int	main(void)
{
	t_list	*ptr;

	t_list *lst = ft_lstnew((char *) "World");
	t_list *newnode = ft_lstnew((char *) "Hello");

	ft_lstadd_front(&lst, newnode);
	ptr = ft_lstlast(lst);
	printf ("%s", (char *) ptr->content);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 20:26:05 by llinda            #+#    #+#             */
/*   Updated: 2026/06/30 11:22:21 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	nb;

	nb = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		nb++;
		lst = lst->next;
	}
	return (nb);
}

/* int	main(void)
{
	t_list *lst = ft_lstnew((char *) "World");
	t_list *newnode = ft_lstnew((char *) "Hello");

	ft_lstadd_front(&lst, newnode);
	printf ("%d", ft_lstsize(lst));
} */

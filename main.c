/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 13:45:41 by llinda            #+#    #+#             */
/*   Updated: 2026/08/09 13:06:49 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>
#include <stddef.h>

void	s(t_dlist **head)
{
	int	saved;

	saved = (**head).content;
	(**head).content = (*((**head).next)).content;
	(*((**head).next)).content = saved;
}

void	p(t_dlist **a, t_dlist **b, t_data *data)
{
	*b = ft_dlstadd_front(data, ft_dlstnew((*a)->content));
//	(*a)->prev->next = (*a)->next;
//	(*a)->next->prev = (*a)->prev;
}

void	r(t_dlist **head)
{
	*head = (*head)->next;
}

void	rr(t_dlist **head)
{
	*head = (*head)->prev;
}

t_dlist	*create_a(int *args, t_data *data)
{
	size_t	i;
	t_dlist	*head;
	t_dlist	*node;

	i = 0;
	head = ft_dlstadd_back(data, ft_dlstnew(args[i++]));
	while (i < 6)
	{
		node = ft_dlstnew(args[i++]);
		ft_dlstadd_back(data, node);
	}
	head->prev = data->tail;
	data->tail->next = head;
	data->tail = NULL; //clean data->tail&head
	return (head);
}

void	bubble_sort(t_dlist **a, t_dlist **b, t_data *data)
{
	size_t	swap_cnt;
	bool	check;
	t_dlist	*first;

	first = *a;
	swap_cnt = 1;
	while (swap_cnt > 0)
	{
		swap_cnt = 0;
		check = false;
		while (check == false || (*a)->next != first)
		{
			if ((*a)->content > (*a)->next->content)
			{
				s(a);
				swap_cnt++;
			}
			r(a);
			check = true;
		}
		if (swap_cnt != 0)
		{
			p(a, b, data);
			ft_dlstdelone(a);
		}
		else
		{
			while (*b)
			{
				r(a);
				p(b, a, data);
				ft_dlstdelone(b);
			}
		}
	}
}

int	main()
{
	t_dlist	*a;
	t_dlist	*b;
	t_data	data;
	int		args[6] = {2,1,3,5,6,4};

	a = NULL;
	b = NULL;
	data.head = NULL;
	data.tail = NULL;
	a = create_a(args, &data);
	bubble_sort(&a, &b, &data);
	lst_printer(b);
}
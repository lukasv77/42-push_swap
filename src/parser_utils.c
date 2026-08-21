/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmankows <mmankows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 08:01:35 by mmankows          #+#    #+#             */
/*   Updated: 2026/08/11 08:01:35 by mmankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int	ft_safe_atoi(char *str, int *error)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i])
	{
		res = res * 10 + (str[i++] - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && (-res) < INT_MIN))
		{
			*error = 1;
			return (0);
		}
	}
	return ((int)(res * sign));
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	*join_args(char **argv)
{
	char	*joined;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (argv[i])
	{
		if (!argv[i][0])
			return (NULL);
		len += ft_strlen(argv[i++]) + 1;
	}
	joined = ft_calloc(len + 1, sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	while (argv[i])
	{
		ft_strlcat(joined, argv[i++], len + 1);
		ft_strlcat(joined, " ", len + 1);
	}
	return (joined);
}

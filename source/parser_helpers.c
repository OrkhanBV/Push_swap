/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 00:56:48 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/13 21:03:55 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "header.h"
#include "../includes/libft/libft.h"

void		ft_free_null(char **tmp)
{
	if (*tmp)
	{
		free(*tmp);
	}
	*tmp = NULL;
}

int			just_iter(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

int			ft_strisnum(char *str)
{
	int i;
	int j;

	i = 1;
	j = 1;
	if (!str)
		return (0);
	if (check_fisrt_zero(str) == 1)
		return (0);
	if (ft_case_sign(str) == 0)
		return (0);
	if (ft_case_no_sign(str) == 0)
		return (0);
	return (1);
}

int			ft_check_sign_witout_nbr(char *tmp)
{
	int i;

	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '-' || tmp[i] == '+')
		{
			if (tmp[i + 1] == ' ' || tmp[i + 1] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

t_list		*ft_get_int(char **tmp, t_list **list)
{
	t_list	*tmp_l;
	int		data;

	tmp_l = *list;
	data = 0;
	if (*tmp && (ft_strisnum(*tmp)) == 1)
	{
		if ((ft_longatoi(*tmp) > 2147483647) ||
			((ft_longatoi(*tmp) < -2147483648)))
		{
			ft_lst_free_chain(&(tmp_l));
			return (NULL);
		}
		if (ft_check_sign_witout_nbr(*tmp) == 0)
		{
			data = ft_atoi(*tmp);
			tmp_l = ft_add_to_bottom(&tmp_l, data);
		}
	}
	else if (*tmp && (ft_strisnum(*tmp)) == 0)
	{
		ft_lst_free_chain(&(tmp_l));
		return (NULL);
	}
	return (tmp_l);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:22:36 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 21:21:50 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "header.h"
#include "../includes/libft/libft.h"

int			ft_case_sign(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		while (str[i] != '\0')
		{
			if ((ft_isdigit(str[i])) == 0)
				return (0);
			i++;
		}
		if ((i - 1) > 11)
			return (0);
		if (str[i] == '\0' && i != 1)
			return (1);
	}
	return (1);
}

int			ft_case_no_sign(char *str)
{
	int j;

	j = 0;
	if (str[j] != '-' && str[j] != '+')
	{
		while (str[j] != '\0')
		{
			if (str[j] != '\0')
				if ((ft_isdigit(str[j])) == 0)
					return (0);
			j++;
		}
		if ((j - 1) > 11)
			return (0);
	}
	return (1);
}

t_list		*body_read_args(char *str, t_list *tmp_l, int i, char *tmp)
{
	int j;
	int	iter;

	j = 0;
	iter = 0;
	while (str[iter] != '\0')
	{
		j = 0;
		i = just_iter(str, i);
		tmp = prep_memmory_for_digits(str, tmp, i);
		while (str[i] == '-' || str[i] == '+' ||
			(str[i] >= '0' && str[i] <= '9'))
			tmp[j++] = str[i++];
		if (j != 0)
			tmp[j] = '\0';
		if (!(tmp_l = ft_get_int(&tmp, &tmp_l)))
		{
			ft_free_null(&tmp);
			return (NULL);
		}
		ft_free_null(&tmp);
		iter++;
	}
	ft_free_null(&tmp);
	return (tmp_l);
}

t_list		*reed_args(char *str, t_list **a, int i, char *tmp)
{
	t_list	*tmp_l;

	tmp_l = *a;
	if (!str)
		return (NULL);
	tmp_l = body_read_args(str, tmp_l, i, tmp);
	ft_free_null(&tmp);
	return (tmp_l);
}

int			parser(char **argv, t_list **a, int argc)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = NULL;
	i = 1;
	j = 0;
	while (i < argc)
	{
		if (check_elem_of_arg(argv[i]) != 1)
			return (0);
		if ((*a = reed_args(argv[i], a, j, tmp)) == NULL)
			return (0);
		i++;
	}
	return (1);
}

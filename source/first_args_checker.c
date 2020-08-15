/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_args_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 20:45:31 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/13 23:22:59 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_check_args(char *tmp)
{
	int i;

	i = 0;
	while ((tmp[i] == '-' || tmp[i] == '+' || tmp[i] == ' ' || tmp[i] == '0' ||
		tmp[i] == '1' || tmp[i] == '2' || tmp[i] == '3' || tmp[i] == '4' ||
		tmp[i] == '5' || tmp[i] == '6' || tmp[i] == '7' || tmp[i] == '8' ||
		tmp[i] == '9'))
	{
		if (tmp[i] == '-' || tmp[i] == '+')
		{
			if (tmp[i + 1] == ' ' || tmp[i + 1] == '\0')
				return (1);
		}
		if (tmp[i] == '\0')
			return (0);
		i++;
	}
	if (tmp[i] != '\0')
		return (1);
	return (0);
}

int			check_empty_args(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
	{
		if (str[0] == '\0' || str[i] == '\0')
			return (1);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

void		first_args_checker(int argc, char **argv)
{
	int i;

	i = 1;
	while (argv[i] && argc > i)
	{
		if (check_empty_args(argv[i]) == 1)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	i = 1;
	while (argv[i] && argc > i)
	{
		if (argv[i] && ft_check_args(argv[i]) == 1)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	return ;
}

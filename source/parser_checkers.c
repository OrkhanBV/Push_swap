/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checkers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 01:01:02 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/13 03:36:33 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "header.h"
#include "../includes/libft/libft.h"

int			check_elem_of_arg(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || (str[i] == '-' || str[i] == '+') ||
		(str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] == '-' || str[i] == '+')
			if (str[i + 1] == ' ' || str[i + 1] == '\0')
				return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	else
		return (0);
	return (1);
}

char		*prep_memmory_for_digits(char *str, char *tmp, int i)
{
	if (tmp != NULL)
	{
		free(tmp);
		tmp = NULL;
	}
	if (str[i] == '-' || str[i] == '+' ||
		(str[i] >= '0' && str[i] <= '9'))
	{
		if (tmp != NULL)
			free(tmp);
		tmp = NULL;
		tmp = (char*)malloc(4096 * sizeof(char));
	}
	return (tmp);
}

int			check_fisrt_zero(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '0')
			return (1);
	}
	if (str[i] == '0')
	{
		if (str[i + 1] == '0')
			return (1);
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			return (1);
		if (str[i + 1] == '\0')
			return (0);
	}
	return (0);
}

int			check_last_s(char c, char *tmp)
{
	if (c == '\0')
	{
		if (tmp != NULL)
			free(tmp);
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list_chains.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 01:21:04 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 16:28:39 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_lst_free_chain(t_list **chain)
{
	t_list	*temp;

	while (*chain)
	{
		temp = *chain;
		*chain = (*chain)->next;
		if (temp != NULL)
			free(temp);
	}
	*chain = NULL;
}

void		ft_free_struct(t_ab *ab)
{
	if (ab->a)
		ft_lst_free_chain(&(ab->a));
	if (ab->b)
		ft_lst_free_chain(&(ab->b));
	return ;
}

void		free_int_arr(int **a_arr)
{
	if (*a_arr)
		free(*a_arr);
}

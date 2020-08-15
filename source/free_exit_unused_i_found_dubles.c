/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_unused_i_found_dubles.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:49:11 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 16:27:04 by jremarqu         ###   ########.fr       */
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

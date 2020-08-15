/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:48:35 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 14:50:04 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_order(t_list **a)
{
	t_list	*at;
	int		c;
	int		pr;

	c = 0;
	pr = 0;
	at = *a;
	while (at)
	{
		if (!at->next)
			return (1);
		pr = at->data;
		c = at->next->data;
		if (c < pr)
			return (0);
		at = at->next;
	}
	return (1);
}

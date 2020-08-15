/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:21:11 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 14:51:41 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_dubles(t_list **a_head)
{
	t_list *checkit;
	t_list *tmp;

	checkit = *a_head;
	while (checkit)
	{
		tmp = *a_head;
		while (tmp)
		{
			if (tmp == checkit && tmp->next)
				tmp = tmp->next;
			if (tmp == checkit && !tmp->next)
				return (0);
			if (tmp->data == checkit->data)
			{
				ft_lst_free_chain(&*a_head);
				return (1);
			}
			tmp = tmp->next;
		}
		checkit = checkit->next;
	}
	return (0);
}

t_ab	*pars_and_check(char **argv, int argc)
{
	t_ab	*ab;
	t_list	*a;

	a = NULL;
	if (!(ab = (t_ab*)malloc(sizeof(t_ab))))
		return (NULL);
	ab->a = NULL;
	ab->b = NULL;
	if (!(parser(argv, &a, argc)))
	{
		free(ab);
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	if (check_dubles(&a) != 0)
	{
		free(ab);
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	ab->a = a;
	return (ab);
}

int		check_stack_b(t_list **b)
{
	if ((*b)->next == NULL)
		return (1);
	return (0);
}

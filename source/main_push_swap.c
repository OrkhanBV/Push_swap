/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:21:44 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/13 20:59:10 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void		write_error(t_ab ab)
{
	ft_putstr_fd("Error\n", 2);
	ft_free_struct(&ab);
}

int			check_argc(int argc)
{
	if (argc == 1)
		return (1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_ab	ab;

	ab.a = NULL;
	ab.b = NULL;
	if ((check_argc(argc)) == 1)
		return (0);
	first_args_checker(argc, argv);
	if (!(parser(argv, &(ab.a), argc)))
	{
		write_error(ab);
		exit(1);
	}
	if (check_dubles(&(ab.a)) != 0)
	{
		write_error(ab);
		exit(1);
	}
	if (check_order(&(ab.a)) == 1)
	{
		ft_free_struct(&ab);
		return (0);
	}
	algo_manager(&ab);
	ft_free_struct(&ab);
	return (0);
}

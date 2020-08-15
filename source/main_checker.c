/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 19:30:32 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/13 20:56:51 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			final_check(t_list *a_list, t_list *b_list)
{
	if (b_list == NULL)
	{
		if (check_order(&a_list) == 0)
		{
			write(1, "KO\n", 3);
			return (1);
		}
		else if (check_order(&a_list) == 1)
		{
			write(1, "OK\n", 3);
			return (0);
		}
	}
	if (b_list != NULL)
		write(1, "KO\n", 3);
	return (0);
}

int			program_run_reader(t_ab *ab)
{
	char	*line;
	int		len_stack_a;

	line = NULL;
	len_stack_a = size_of_list(&(ab->a));
	while (get_next_line(0, &line) > 0)
	{
		run_operators_i(line, &(ab->a), &(ab->b));
		free(line);
		line = NULL;
	}
	len_stack_a = final_check(ab->a, ab->b);
	ft_free_struct(ab);
	while (line)
		free(line);
	free(ab);
	return (0);
}

int			main(int argc, char **argv)
{
	t_ab	*ab;

	if (argc <= 1)
		return (0);
	ab = NULL;
	first_args_checker(argc, argv);
	if ((ab = pars_and_check(argv, argc)) == NULL)
	{
		free(ab);
		return (0);
	}
	if (program_run_reader(ab) == 0)
		return (0);
	return (0);
}

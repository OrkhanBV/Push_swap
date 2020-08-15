/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_operators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:24:29 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/13 17:42:53 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		case_sa_sb_ss(t_list **a, t_list **b, char *line)
{
	if (ft_strcmp("sa", line) == 0)
	{
		if (sai(a) == 1)
			return (1);
		return (0);
	}
	else if (ft_strcmp("sb", line) == 0)
	{
		if (sbi(b) == 1)
			return (1);
		return (0);
	}
	else if (ft_strcmp("ss", line) == 0)
	{
		if (ssi(a, b) == 1)
			return (1);
		return (0);
	}
	else
		return (-1);
}

int		case_pa_pb(t_list **a, t_list **b, char *line)
{
	if (ft_strcmp("pa", line) == 0)
	{
		if (pai(a, b) == 1)
			return (1);
		return (0);
	}
	else if (ft_strcmp("pb", line) == 0)
	{
		if (pbi(a, b) == 1)
			return (1);
		return (0);
	}
	else
		return (-1);
}

int		case_ra_rb_rr(t_list **a, t_list **b, char *line)
{
	if (ft_strcmp("ra", line) == 0)
	{
		if (rai(a) == 1)
			return (1);
		return (0);
	}
	else if (ft_strcmp("rb", line) == 0)
	{
		if (rbi(b) == 1)
			return (1);
		return (0);
	}
	else if (ft_strcmp("rr", line) == 0)
	{
		if (rri(a, b) == 1)
			return (1);
		return (0);
	}
	else
		return (-1);
}

int		case_rra_rrb_rrr(t_list **a, t_list **b, char *line)
{
	if (ft_strcmp("rra", line) == 0)
	{
		if (rrai(a) == 1)
			return (1);
		return (0);
	}
	else if (ft_strcmp("rrb", line) == 0)
	{
		if (rrbi(b) == 1)
			return (1);
		return (0);
	}
	else if (ft_strcmp("rrr", line) == 0)
	{
		if (rrri(a, b) == 1)
			return (1);
		return (0);
	}
	else
		return (-1);
}

int		run_operators_i(char *line, t_list **ar, t_list **br)
{
	int res;

	if ((res = case_sa_sb_ss(ar, br, line)) >= 0)
		return (res);
	else if ((res = case_pa_pb(ar, br, line)) >= 0)
		return (res);
	else if ((res = case_ra_rb_rr(ar, br, line)) >= 0)
		return (res);
	else if ((res = case_rra_rrb_rrr(ar, br, line)) >= 0)
		return (res);
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (0);
}

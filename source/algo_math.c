/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:20:50 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 14:39:52 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			f_min(t_list **list)
{
	t_list	*arr;
	int		min;

	min = 0;
	arr = *list;
	if (arr)
	{
		min = arr->data;
		while (arr)
		{
			if (min > arr->data)
				min = arr->data;
			arr = arr->next;
		}
	}
	return (min);
}

int			f_max(t_list **list)
{
	t_list	*arr;
	int		max;

	max = 0;
	arr = *list;
	if (arr)
	{
		while (arr)
		{
			if (max < arr->data)
				max = arr->data;
			arr = arr->next;
		}
	}
	return (max);
}

int			medi(int *arr, int last_index)
{
	int i;
	int *tmp;
	int res;

	i = 0;
	tmp = (int*)malloc((last_index + 1) * sizeof(int));
	while (i <= last_index)
	{
		tmp[i] = arr[i];
		i++;
	}
	quicksort(tmp, 0, (last_index));
	i = ((last_index) / 2);
	res = tmp[i];
	free(tmp);
	return (res);
}

int			*create_arr_from_list(t_list **a_list, int stack_len)
{
	t_list	*tmp;
	int		*arr;
	int		i;

	i = 0;
	if (!(arr = (int *)malloc((stack_len + 1) * sizeof(int))))
		return (0);
	tmp = *a_list;
	while (tmp)
	{
		arr[i] = tmp->data;
		i++;
		tmp = tmp->next;
	}
	return (arr);
}

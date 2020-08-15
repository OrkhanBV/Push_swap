/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:23:29 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/12 16:59:25 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		help_qs(int *arr, int *tmp, int *left, int *right)
{
	*tmp = arr[*left];
	arr[*left] = arr[*right];
	arr[*right] = *tmp;
	*left += 1;
	*right -= 1;
}

void			quicksort(int *arr, int first, int last)
{
	int tmp;
	int left;
	int right;
	int middle;

	if (first < last)
	{
		left = first;
		right = last;
		middle = arr[(left + right) / 2];
		while (left <= right)
		{
			while (arr[left] < middle)
				left++;
			while (arr[right] > middle)
				right--;
			if (left <= right)
				help_qs(arr, &tmp, &left, &right);
		}
		quicksort(arr, first, right);
		quicksort(arr, left, last);
	}
}

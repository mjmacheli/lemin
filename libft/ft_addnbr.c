/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 00:21:47 by mmacheli          #+#    #+#             */
/*   Updated: 2018/06/24 07:15:47 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_addnbr(int **arr, int a)
{
	int index;
	int index2;
	int *tmp;

	index2 = sizeof(*arr);
	index = sizeof(*arr[0]);
	index = index /index2;
	index2 = 0;
	if (!(tmp = (int*)malloc(sizeof(int ) * index)))
		return ;
	while (index2 < index)
	{
		tmp[index2] = *arr[index2];
		index2++;
	}
	index2 = 0;
	if (!(*arr = (int*)malloc(sizeof(int) * (index + 1))))
		return ;
	while (index2 < index)
	{
		*arr[index2] = tmp[index2];
		index2++;
	}
	*arr[index2] = a;
	free(tmp);
	tmp = NULL;
}

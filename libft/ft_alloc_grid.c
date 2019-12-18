/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:16:53 by mmacheli          #+#    #+#             */
/*   Updated: 2018/09/11 15:20:38 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_alloc_grid(size_t n)
{
	char	**grid;
	int		index;

	if (!(grid = (char**)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	index = 0;
	while (index < n + 1)
		grid[index++] = NULL;
	return (grid);
}

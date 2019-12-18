/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 13:45:06 by mmacheli          #+#    #+#             */
/*   Updated: 2018/08/03 12:23:23 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_contains(char *s, char c)
{
	int index;

	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			return (1);
		index++;
	}
	return (0);
}

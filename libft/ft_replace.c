/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 23:40:00 by mmacheli          #+#    #+#             */
/*   Updated: 2018/08/28 17:30:53 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_replace(char **str, char a, char b)
{
	int		index;

	index = 0;
	while ((*str)[index])
	{
		if ((*str)[index] == a)
			(*str)[index] = b;
		index++;
	}
}

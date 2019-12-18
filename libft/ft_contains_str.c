/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:19:17 by mmacheli          #+#    #+#             */
/*   Updated: 2018/09/13 12:38:14 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_contains_str(char **argv, char *str, int len)
{
	int		index;

	index = 0;
	while (index < len)
	{
		if (ft_strequ(argv[index], str))
			return (1);
		index++;
	}
	return (0);
}

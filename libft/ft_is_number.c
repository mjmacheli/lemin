/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 11:55:02 by mmacheli          #+#    #+#             */
/*   Updated: 2018/09/10 08:40:23 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_number(char *s)
{
	int index;

	if (!s || ft_strlen(s) == 0)
		return (0);
	index = 0;
	if (s[index] == '+' || s[index] == '-')
		index++;
	while (s[index])
	{
		if (!ft_isdigit(s[index]))
			return (0);
		index++;
	}
	return (1);
}

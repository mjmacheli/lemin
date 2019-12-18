/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:56:25 by mmacheli          #+#    #+#             */
/*   Updated: 2018/06/13 12:20:36 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *u_s1;
	unsigned char *u_s2;

	u_s1 = (unsigned char*)s1;
	u_s2 = (unsigned char*)s2;
	while (*u_s1 && *u_s2)
	{
		if ((*u_s1 > *u_s2) || (*u_s1 < *u_s2))
			return (*u_s1 - *u_s2);
		u_s1++;
		u_s2++;
	}
	return (*u_s1 - *u_s2);
}

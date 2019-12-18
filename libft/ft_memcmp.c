/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:32:45 by mmacheli          #+#    #+#             */
/*   Updated: 2018/06/11 16:36:47 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	u_s1 = (unsigned char*)s1;
	u_s2 = (unsigned char*)s2;
	while (n--)
	{
		if ((*u_s1 > *u_s2) || (*u_s1 < *u_s2))
			return (*u_s1 - *u_s2);
		u_s1++;
		u_s2++;
	}
	return (0);
}

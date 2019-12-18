/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:45:15 by mmacheli          #+#    #+#             */
/*   Updated: 2018/06/16 12:02:23 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*u_dst;
	unsigned char	*u_src;

	index = 0;
	u_dst = (unsigned char*)dst;
	u_src = (unsigned char*)src;
	while (index < n)
	{
		u_dst[index] = u_src[index];
		index++;
	}
	return (u_dst);
}

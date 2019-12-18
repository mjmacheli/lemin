/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:52:52 by mmacheli          #+#    #+#             */
/*   Updated: 2018/06/10 12:03:34 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*u_dst;
	const char	*u_src;
	size_t		index;

	index = 0;
	u_dst = (char*)dst;
	u_src = (const char*)src;
	if (n <= 0)
		return (u_dst);
	if (u_src < u_dst)
	{
		index = n;
		while (index)
		{
			u_dst[index - 1] = u_src[index - 1];
			index--;
		}
	}
	else
		ft_memcpy(u_dst, u_src, n);
	return (u_dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:02:40 by mmacheli          #+#    #+#             */
/*   Updated: 2018/06/11 16:37:41 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*u_b;
	unsigned char	u_c;
	int				index;

	u_b = (unsigned char*)b;
	u_c = (unsigned char)c;
	index = 0;
	while (n--)
	{
		u_b[index++] = u_c;
	}
	return (u_b);
}

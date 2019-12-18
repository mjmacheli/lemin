/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:46:40 by mmacheli          #+#    #+#             */
/*   Updated: 2018/06/02 22:56:42 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	u_c;
	char			*s_hold;

	s_hold = (char*)s;
	u_c = c;
	while (*s_hold)
	{
		if (*s_hold == u_c)
			return (s_hold);
		if (*++s_hold == u_c && u_c == '\0')
			return (s_hold);
	}
	return (NULL);
}

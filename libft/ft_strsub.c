/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 14:48:47 by mmacheli          #+#    #+#             */
/*   Updated: 2018/06/24 08:07:10 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	char	*sub;
	size_t	index;

	index = 0;
	if (!s1 || !(sub = ft_strnew(len)))
		return (NULL);
	while (index < len)
		sub[index++] = s1[start++];
	return (sub);
}

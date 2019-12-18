/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:22:40 by mmacheli          #+#    #+#             */
/*   Updated: 2018/06/24 07:17:26 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		index;

	if (!s)
		return (NULL);
	ret = ft_strnew(ft_strlen(s));
	if (ret == NULL)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		ret[index] = f(s[index]);
		index++;
	}
	return (ret);
}

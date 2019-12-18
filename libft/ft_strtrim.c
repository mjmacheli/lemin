/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:03:14 by mmacheli          #+#    #+#             */
/*   Updated: 2018/09/13 13:08:12 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*ret;
	size_t			len;
	unsigned int	start;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	start = 0;
	while (len)
	{
		if (s[len - 1] != ' ' && s[len - 1] != '\t' && s[len - 1] != '\n')
			break ;
		len--;
	}
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	ret = ft_strsub(s, start > len ? 0 : start, len > start ? len - start : 0);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 10:53:21 by mmacheli          #+#    #+#             */
/*   Updated: 2018/06/20 15:30:10 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*ret;
	size_t	len_little;

	ret = (char*)big;
	len_little = ft_strlen((char*)little);
	if (*ret && len_little == 0)
		return (ret);
	while (*ret)
	{
		if (ft_strncmp(ret, little, len_little) == 0)
			return (ret);
		ret++;
	}
	if (ret == little)
		return (ret);
	return (NULL);
}

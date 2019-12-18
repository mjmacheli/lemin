/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:54:06 by mmacheli          #+#    #+#             */
/*   Updated: 2018/06/18 08:24:38 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		rev_index;
	char	*temp_s;

	temp_s = (char*)s;
	rev_index = ft_strlen(temp_s);
	while (rev_index > 0 && (temp_s[rev_index] != c))
		rev_index--;
	if (temp_s[rev_index] == c)
		return (temp_s + rev_index);
	else
		return (NULL);
}

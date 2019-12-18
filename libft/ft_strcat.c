/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:09:27 by mmacheli          #+#    #+#             */
/*   Updated: 2018/05/29 16:44:45 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int index;
	int length;

	length = ft_strlen(s1);
	index = 0;
	while (s2[index] != '\0')
		s1[length++] = s2[index++];
	s1[length] = '\0';
	return (s1);
}

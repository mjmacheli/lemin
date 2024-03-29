/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:02:44 by mmacheli          #+#    #+#             */
/*   Updated: 2018/06/18 08:25:34 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int	ret;

	if (!s1 || !s2)
		return (0);
	ret = ft_strcmp(s1, s2);
	if (ret == 0)
		return (1);
	return (0);
}

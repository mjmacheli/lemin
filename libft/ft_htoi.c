/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 13:52:43 by mmacheli          #+#    #+#             */
/*   Updated: 2018/08/08 14:32:02 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

int		ft_htoi(const char *s)
{
	unsigned int	ret;
	int					index;

	index = 0;
	ret = 0;
	while ((int)ft_strlen(s) - (++index) >= 0)
	{
		if (s[index - 1] == 'a' || s[index - 1] == 'A')
			ret += 10 * (pow(16, (ft_strlen(s) - index)));
		else if (s[index - 1] == 'b' || s[index - 1] == 'B')
			ret += 11 * (pow(16, (ft_strlen(s) - index)));
		else if (s[index - 1] == 'c' || s[index - 1] == 'C')
			ret += 12 * (pow(16, (ft_strlen(s) - index)));
		else if (s[index - 1] == 'd' || s[index - 1] == 'D')
			ret += 13 * (pow(16, (ft_strlen(s) - index)));
		else if (s[index - 1] == 'e' || s[index - 1] == 'E')
			ret += 14 * (pow(16, (ft_strlen(s) - index)));
		else if (s[index - 1] == 'f' || s[index - 1] == 'F')
			ret += 15 * (pow(16, (ft_strlen(s) - index)));
		else if (ft_isdigit(s[index - 1]))
			ret += (s[index - 1] - '0') * (pow(16, (ft_strlen(s) - index)));
		else
			return (-1);
	}
	return (ret > 2147483647 ? -1 : ret);
}

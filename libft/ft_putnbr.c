/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 02:57:31 by mmacheli          #+#    #+#             */
/*   Updated: 2018/06/11 16:39:25 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	div;
	char	c;
	long	temp_n;

	temp_n = (long)n;
	div = 1;
	if (n < 0)
	{
		ft_putchar('-');
		temp_n *= -1;
	}
	if (n == 0)
		ft_putchar('0');
	while (div <= temp_n)
		div *= 10;
	div /= 10;
	while (div != 0)
	{
		c = (temp_n / div) + 48;
		ft_putchar(c);
		temp_n %= div;
		div /= 10;
	}
}

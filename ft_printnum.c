/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:59:04 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/04 12:59:06 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static int	count_size(long n)
{
	int		counter;

	counter = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		counter++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

void	ft_printnum(int num, int *len)
{
	int		i;
	long	n;

	n = num;
	i = count_size(n);
	ft_putnbr_fd(n, 1);
	(*len) += i;
}

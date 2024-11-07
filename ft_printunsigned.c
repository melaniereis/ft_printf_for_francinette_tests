/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:59:21 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/04 12:59:23 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_printunsigned(unsigned int num, int *len)
{
	if (num >= 10)
		ft_printunsigned(num / 10, len);
	ft_printchar((num % 10) + '0', len);
}

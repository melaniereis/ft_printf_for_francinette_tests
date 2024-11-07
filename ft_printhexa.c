/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:59:38 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/04 12:59:41 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_printhexa(unsigned long long num, const char format, int *len)
{
	char	*hex;

	if (format == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (num >= 16)
		ft_printhexa(num / 16, format, len);
	ft_printchar(hex[num % 16], len);
}

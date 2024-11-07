/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:58:52 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/04 12:58:55 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_printpointer(void *ptr, int *len)
{
	unsigned long long	address;

	if (ptr == NULL)
	{
		ft_printstring("(nil)", len);
		return ;
	}
	address = (unsigned long long)ptr;
	ft_printstring("0x", len);
	ft_printhexa(address, 'x', len);
}

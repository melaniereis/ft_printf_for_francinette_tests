/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:58:26 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/04 12:58:30 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_printstring(char *str, int *len)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		(*len) += 6;
		return ;
	}
	while (*str)
	{
		ft_printchar(*str, len);
		str++;
	}
}

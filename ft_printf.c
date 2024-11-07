/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:48:51 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/04 10:49:40 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static void	ft_printfcheck(char s, va_list *args, int *len)
{
	if (s == 'c')
		ft_printchar(va_arg(*args, int), len);
	else if (s == 's')
		ft_printstring(va_arg(*args, char *), len);
	else if (s == 'p')
		ft_printpointer(va_arg(*args, void *), len);
	else if (s == 'd' || s == 'i')
		ft_printnum(va_arg(*args, int), len);
	else if (s == 'u')
		ft_printunsigned(va_arg(*args, unsigned int), len);
	else if (s == 'x' || s == 'X')
		ft_printhexa(va_arg(*args, unsigned int), s, len);
	else if (s == '%')
		ft_printchar('%', len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			ft_printfcheck(str[i + 1], &args, &len);
			i++;
		}
		else if (str[i] == '\\' && str[i + 1] == 'n')
		{
			ft_printchar('\n', &len);
			i++;
		}
		else
			ft_printchar(str[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:00:52 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/17 16:08:53 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	if (!*s)
		return (0);
	while (s[size])
		size++;
	return (size);
}

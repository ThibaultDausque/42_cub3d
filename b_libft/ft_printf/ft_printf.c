/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:29:49 by tdausque          #+#    #+#             */
/*   Updated: 2024/10/29 10:57:29 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_check(va_list args, char c)
{
	int		j;

	j = 0;
	if (c == 'c')
		j = ft_print_char(va_arg(args, int));
	else if (c == 's')
		j = ft_print_str(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		j = ft_print_nbr(va_arg(args, int));
	else if (c == 'u')
		j = ft_print_unbr(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		j = ft_print_hex(va_arg(args, int), c);
	else if (c == 'p')
	{
		j += ft_print_ptr(va_arg(args, unsigned long));
	}
	else if (c == '%')
		return (ft_print_char('%'));
	return (j);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			i;
	int			k;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '\0')
				k += ft_check(args, str[++i]);
		}
		else
			k += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (k);
}

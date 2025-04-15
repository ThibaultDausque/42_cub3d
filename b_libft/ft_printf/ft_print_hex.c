/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:04:03 by tdausque          #+#    #+#             */
/*   Updated: 2024/10/27 14:10:42 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int nb, char format)
{
	char	*hex;
	int		i;

	i = 0;
	if (format == 'X')
		hex = "0123456789ABCDEF";
	if (format == 'x')
		hex = "0123456789abcdef";
	if (nb > 15)
	{
		i += ft_print_hex(nb / 16, format);
		i += ft_print_hex(nb % 16, format);
	}
	else
		i += ft_print_char(hex[nb % 16]);
	return (i);
}

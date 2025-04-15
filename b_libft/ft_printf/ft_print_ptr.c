/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:29:12 by tdausque          #+#    #+#             */
/*   Updated: 2024/10/29 10:46:07 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr(unsigned long ptr)
{
	char			*base;
	int				j;

	j = 0;
	base = "0123456789abcdef";
	if (ptr >= 16)
	{
		j += ft_ptr(ptr / 16);
		j += ft_ptr(ptr % 16);
	}
	else
		j += ft_print_char(base[ptr % 16]);
	return (j);
}

int	ft_print_ptr(unsigned long ptr)
{
	int		k;

	if (!ptr)
		return (write(1, "(nil)", 5));
	k = 0;
	k += ft_print_str("0x");
	k += ft_ptr(ptr);
	return (k);
}

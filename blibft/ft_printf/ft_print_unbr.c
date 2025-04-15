/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 09:31:08 by tdausque          #+#    #+#             */
/*   Updated: 2024/10/29 09:39:45 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unbr(unsigned int nb)
{
	char	str[10];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (nb > 9)
	{
		j += ft_print_unbr(nb / 10);
		j += ft_print_unbr(nb % 10);
	}
	else
	{
		str[i] = '0' + nb;
		j += write(1, &str[i++], 1);
	}
	return (j);
}

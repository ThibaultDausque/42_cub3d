/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:56:26 by tdausque          #+#    #+#             */
/*   Updated: 2024/10/29 09:37:48 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"

int	ft_print_nbr(int nb)
{
	char	str[10];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (nb == INT_MIN)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
		j++;
	}
	if (nb > 9)
	{
		j += ft_print_nbr(nb / 10);
		j += ft_print_nbr(nb % 10);
	}
	else
	{
		str[i] = '0' + nb;
		j += ft_print_char(str[i++]);
	}
	return (j);
}

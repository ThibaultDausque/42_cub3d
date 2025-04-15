/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:03:34 by tdausque          #+#    #+#             */
/*   Updated: 2024/10/27 14:03:53 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>

int	ft_print_char(char c);
int	ft_print_hex(unsigned int nb, char format);
int	ft_print_nbr(int nb);
int	ft_print_str(char *str);
int	ft_print_ptr(unsigned long ptr);
int	ft_print_unbr(unsigned int nb);
int	ft_printf(const char *str, ...);

#endif
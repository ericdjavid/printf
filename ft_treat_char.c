/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_char2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 10:44:37 by edjavid           #+#    #+#             */
/*   Updated: 2021/04/24 10:44:40 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_treat_char(va_list print_list, the_flags *flags, int nb)
{
	char	c;
	int		count;

	count = 0;
	c = (char)va_arg(print_list,
	int);
	if (flags[nb].minus == 1)
	{
		write(1, &c, 1);
		count++;
	}
	count += ft_treat_width(flags, flags[nb].zero, nb, 1);
	if (flags[nb].minus == 0)
	{
		write(1, &c, 1);
		count++;
	}
	return (count);
}

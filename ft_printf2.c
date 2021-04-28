/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:08:24 by edjavid           #+#    #+#             */
/*   Updated: 2021/04/27 13:08:30 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_args(const char *str)
{
	int nb;
	int i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			nb++;
		i++;
	}
	return (nb);
}

int		check_options(const char *str, the_flags *flags, int i, int nb)
{
	flags[nb].conv_type = '0';
	flags[nb].zero = 0;
	flags[nb].minus = 0;
	while (str[i] == '*' || str[i] == '0' || str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '*')
			flags[nb].star = 1;
		if (str[i] == '0')
			flags[nb].zero = 1;
		if (str[i] == '-')
		{
			flags[nb].minus = 1;
			flags[nb].zero = 0;
		}
		i++;
	}
	return (i);
}

int		ft_printf2(va_list print_list, the_flags *flags, int nb)
{
	int count;

	count = 0;
	if (flags[nb].star)
		flags[nb].width = (int)va_arg(print_list, int);
	if (flags[nb].conv_type == 'c')
		count += ft_treat_char(print_list, flags, nb);
	if (flags[nb].conv_type == 's')
		count += ft_treat_string(print_list, flags, nb);
	if (flags[nb].conv_type == 'd' || flags[nb].conv_type == 'i')
		count += ft_treat_int(print_list, flags, nb);
	if (flags[nb].conv_type == 'p')
		count += ft_treat_pointer(print_list, flags, nb);
	if (flags[nb].conv_type == 'u')
		count += ft_treat_unsigned(print_list, flags, nb);
	if (flags[nb].conv_type == 'x')
		count += ft_treat_x(print_list, flags, nb, 0);
	if (flags[nb].conv_type == 'X')
		count += ft_treat_x(print_list, flags, nb, 1);
	if (flags[nb].conv_type == '%')
	{
		write(1, "%", 1);
		count++;
	}
	return (count);
}

int		ft_printf3(const char *word, va_list printf_list, the_flags *flags)
{
	int		i;
	int		nb;
	int		count;

	i = 0;
	nb = 0;
	count = 0;
	while (word[i])
	{
		if (word[i] == '%' && word[i + 1])
		{
			i = flags[nb].end_position + 1;
			count += ft_printf2(printf_list, flags, nb);
			nb++;
		}
		++count;
		write(1, &word[i], 1);
		i++;
	}
	return (count);
}

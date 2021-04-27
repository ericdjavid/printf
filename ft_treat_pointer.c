/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 10:27:16 by edjavid           #+#    #+#             */
/*   Updated: 2021/04/24 11:35:23 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int		print_minus(int length, the_flags *flags, int nb)
{
	int tmp;

	tmp = length;
	while (flags[nb].width > tmp)
	{
		ft_putchar_fd(' ', 1);
		flags[nb].width--;
		length++;
	}
	return (length);
}

int		compute_options_pt(size_t n, the_flags *flags, int nb)
{
	int length;
	int tmp;

	tmp = 0;
	length = 3;
	if (!flags[nb].width)
		write(1, "0x", 2);
	while (n > 15)
	{
		n /= 16;
		length++;
	}
	while (flags[nb].width > length && !flags[nb].minus)
	{
		ft_putchar_fd(' ', 1);
		length++;
		tmp--;
	}
	if (flags[nb].width)
		write(1, "0x", 2);
	return (length);
}

void	print_hex_p(size_t n)
{
	if (n > 15)
		print_hex_p(n / 16);
	ft_putchar_fd(n % 16 > 9 ? n % 16 + 'a' - 10 : n % 16 + 48, 1);
}

int		ft_treat_pointer(va_list print_list, the_flags *flags, int nb)
{
	size_t pt;
	int count;

	pt = va_arg(print_list, size_t);
	count = compute_options_pt(pt, flags, nb);
	if (flags[nb].precision != -1 || (flags[nb].precision == -1 && pt > 0))
		print_hex_p(pt);
	if (flags[nb].minus)
		count = print_minus(count, flags, nb);
	return (count);
}

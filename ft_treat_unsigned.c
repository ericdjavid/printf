/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 10:27:38 by edjavid           #+#    #+#             */
/*   Updated: 2021/04/24 10:27:40 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int		treat_minus_unsigned(the_flags *flags, int nb, int numb, int i)
{
	int count;

	count = 0;
	if (flags[nb].minus == 1)
		print_dec(numb);
	count += ft_treat_width(flags, flags[nb].zero, nb, i);
	if (!flags[nb].minus)
	{
		if (flags[nb].precision > count_dec(numb))
		{
			i = flags[nb].precision;
			while (i > count_dec(numb))
			{
				ft_putchar_fd('0', 1);
				count++;
				i--;
			}
		}
		print_dec(numb);
	}
	return (count);
}

void	print_dec(unsigned long long n)
{
	if (n > 9)
	{
		print_dec(n / 10);
	}
	ft_putchar_fd((n % 10) + 48, 1);
}

int		count_dec(unsigned long long n)
{
	int length;

	length = 1;
	while (n > 9)
	{
		n /= 10;
		length++;
	}
	return (length);
}

int		ft_treat_unsigned(va_list print_list, the_flags *flags, int nb)
{
	unsigned int	numb;
	int				count;
	int				i;

	numb = (unsigned int)va_arg(print_list, unsigned int);
	count = count_dec(numb);
	if (flags[nb].precision > count_dec(numb))
	{
		i = flags[nb].precision;
		while (i > count_dec(numb) && flags[nb].minus)
		{
			ft_putchar_fd('0', 1);
			count++;
			i--;
		}
		i = flags[nb].precision;
		count += treat_minus_unsigned(flags, nb, numb, i);
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 10:27:01 by edjavid           #+#    #+#             */
/*   Updated: 2021/04/24 11:32:51 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	compute_size(int numb)
{
	int comp;

	comp = 0;
	if (numb < 0)
	{
		numb *= -1;
		comp++;
	}
	while (numb > 0)
	{
		numb /= 10;
		comp++;
	}
	return (comp);
}

int	ft_treat_int(va_list print_list, the_flags *flags, int nb)
{
	int numb;
	int count;
	int i;

	numb = (int)va_arg(print_list, int);
	i = count = compute_size(numb);
	if ((flags[nb].zero && numb < 0) || (flags[nb].precision && numb < 0))
	{
		ft_putchar_fd('-', 1);
		count++;
	}
	if (flags[nb].precision > compute_size(numb))
	{
		i = flags[nb].precision;
		if (numb < 0)
			i++;
		while (i > compute_size(numb) && flags[nb].minus)
		{
			ft_putchar_fd('0', 1);
			count++;
			i--;
		}
		i = flags[nb].precision;
	}
	if (flags[nb].minus == 1)
	{
		if ((numb < 0 && flags[nb].zero) || (numb < 0 && flags[nb].precision))
			ft_putnbr_fd(numb * -1, 1);
		else
			ft_putnbr_fd(numb, 1);
	}
	count += ft_treat_width(flags, flags[nb].zero, nb, i);
	if (!flags[nb].minus)
	{
		if (flags[nb].precision > compute_size(numb))
		{
			i = flags[nb].precision;
			if (numb < 0)
				i++;
			while (i > compute_size(numb))
			{
				ft_putchar_fd('0', 1);
				count++;
				i--;
			}
		}
		if ((numb < 0 && flags[nb].zero) || (numb < 0 && flags[nb].precision))
		{
			ft_putnbr_fd(numb * -1, 1);
		} else
			ft_putnbr_fd(numb, 1);
	}
	return (count);
}

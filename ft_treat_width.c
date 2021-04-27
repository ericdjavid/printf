/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 10:27:53 by edjavid           #+#    #+#             */
/*   Updated: 2021/04/24 10:27:55 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_treat_width(the_flags *flags, int is_zero, int nb, int decrease)
{
	char	c;
	int		i;
	int		count;

	count = 0;
	if (is_zero && !flags[nb].minus)
		c = '0';
	else
		c = ' ';
	i = flags[nb].width - decrease;
	while (i > 0)
	{
		write(1, &c, 1);
		i--;
		count++;
	}
	return (count);
}

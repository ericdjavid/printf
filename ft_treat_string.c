/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 10:27:28 by edjavid           #+#    #+#             */
/*   Updated: 2021/04/24 11:34:09 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_treat_string(va_list print_list, the_flags *flags, int nb)
{
	char	*str;
	int		count;
	int		i;

	i = 0;
	count = 0;
	str = (char *)va_arg(print_list, char*);
	if (flags[nb].precision > 0)
		str = ft_substr(str, 0, flags[nb].precision);
	if (flags[nb].minus == 1)
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
			count++;
		}
	count += ft_treat_width(flags, flags[nb].zero, nb, ft_strlen(str));
	if (flags[nb].minus == 0)
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
			count++;
		}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 10:23:03 by edjavid           #+#    #+#             */
/*   Updated: 2021/04/24 11:30:23 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	check_width(const char *str, the_flags *flags, int i, int nb)
{
	flags[nb].width = 0;
	if (str[i] > '0' && str[i] <= '9')
	{
		while (str[i] > 47 && str[i] < 58)
			flags[nb].width = (flags[nb].width * 10) + str[i++] - 48;
	}
	printf("width is %d\n", flags[nb].width);
	return (i);
}

int	check_precision(const char *str, the_flags *flags, int i, int nb)
{
	flags[nb].precision = 0;
	if (str[i] == '.')
	{
		i++;
		while (str[i] > 47 && str[i] < 58)
			flags[nb].precision = (flags[nb].precision * 10) + str[i++] - 48;
		if (flags[nb].precision == 0)
			flags[nb].precision = -1;
	}
	return (i);
}

int	check_conv_type(const char *str, the_flags *flags, int i, int nb)
{
	int		j;
	char	*str2;

	j = 0;
	str2 = "cspdiuxX%";
	while (str2[j])
	{
		if (str[i] == str2[j])
		{
			flags[nb].conv_type = str2[j];
			return (i);
		}
		j++;
	}
	return (0);
}

int	put_flags(const char *str, the_flags *flags)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			i = check_options(str, flags, i, nb);
			i = check_width(str, flags, i, nb);
			i = check_precision(str, flags, i, nb);
			flags[nb].end_position = i;
			if (!(i = check_conv_type(str, flags, i, nb)))
			{
				free(flags);
				return (0);
			}
			nb++;
		}
		i++;
	}
	return (1);
}

int	ft_printf(const char *word, ...)
{
	va_list		printf_list;
	the_flags	*flags;
	int			count;

	count = 0;
	va_start(printf_list, word);
	if (!(flags = (the_flags *)malloc(sizeof(the_flags) * ft_get_args(word))))
		return (0);
	if (!(put_flags(word, flags)))
		return (0);
	count += ft_printf3(word, printf_list, flags);
	va_end(printf_list);
	return (count);
}

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

int	ft_get_args(const char *str)
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
	printf("\nthere are %d args", nb);
	return (nb);
}

int	check_options(const char *str, the_flags *flags, int i, int nb)
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
	int			i;
	int			nb;
	int			count;

	i = 0;
	nb = 0;
	va_start(printf_list, word);
	count = 0;
	if (!(flags = (the_flags *) malloc(sizeof(the_flags) * ft_get_args(word))))
		return (0);
	if (!(put_flags(word, flags)))
		return (0);
	while (word[i])
	{
		if (word[i] == '%' && word[i + 1])
		{
			i = flags[nb].end_position + 1;
			if (flags[nb].star)
			{
				flags[nb].width = (int) va_arg(printf_list, int);
			}
			if (flags[nb].conv_type == 'c')
			{
				count += ft_treat_char(printf_list, flags, nb);
			} else if (flags[nb].conv_type == 's')
			{
				count += ft_treat_string(printf_list, flags, nb);
			} else if (flags[nb].conv_type == 'd' || flags[nb].conv_type == 'i')
			{
				count += ft_treat_int(printf_list, flags, nb);
			} else if (flags[nb].conv_type == 'p')
			{
				count += ft_treat_pointer(printf_list, flags, nb);
			} else if (flags[nb].conv_type == 'u')
			{
				count += ft_treat_unsigned(printf_list, flags, nb);
			} else if (flags[nb].conv_type == 'x')
			{
				count += ft_treat_x(printf_list, flags, nb, 0);
			} else if (flags[nb].conv_type == 'X')
			{
				count += ft_treat_x(printf_list, flags, nb, 1);
			} else if (flags[nb].conv_type == '%')
			{
				write(1, "%", 1);
				count++;
			}
			nb++;
		}
		++count;
		write(1, &word[i], 1);

		i++;
	}
	va_end(printf_list);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 10:23:35 by edjavid           #+#    #+#             */
/*   Updated: 2021/04/24 11:39:45 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

typedef struct  the_flags {
    char    conv_type;
    int     width;
    int     minus;
    int     zero;
    int     precision;
    int     star;
    int     end_position;
}   the_flags;

int             ft_printf(const char *, ...);
int				ft_printf2(va_list print_list, the_flags *flags, int nb);
int				ft_printf3(const char* word, va_list print_list, the_flags *flags);
int             ft_treat_char(va_list print_list, the_flags *flags, int nb);
int             ft_treat_width(the_flags *flags, int is_zero, int nb, int decrease);
int             ft_treat_string(va_list print_list, the_flags *flags, int nb);
int             ft_treat_int(va_list print_list, the_flags *flags, int nb);
int				not_minus(the_flags *flags, int nb, int numb, int i);
int				treat_minus_unsigned(the_flags *flags, int nb, int numb, int i);
int             ft_treat_pointer(va_list print_list, the_flags *flags, int nb);
int				check_options(const char *str, the_flags *flags, int i, int nb);
int             compute_size(int numb);
void			print_hex_p(size_t n);
int				treat_int_put_zero(int i, int numb);
int	            compute_options_pt(size_t n, the_flags *flags, int nb);
int             print_minus(int length, the_flags *flags, int nb);
int             ft_treat_unsigned(va_list print_list, the_flags *flags, int nb);
void            print_dec(unsigned long long n);
int             count_dec(unsigned long long n);
int             ft_treat_x(va_list print_list, the_flags *flags, int nb, int is_maj);
int				treat_minus_x(the_flags *flags, int nb, unsigned long long x, int is_maj);
int				print_hex_x(unsigned long long n, int is_maj);
int             count_x(unsigned long long n);
int				ft_get_args(const char *str);
#endif

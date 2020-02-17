/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzerates <tzerates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:30:11 by tzerates          #+#    #+#             */
/*   Updated: 2020/02/17 18:46:59 by tzerates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

typedef struct	s_flags
{
	int	minus;
	int	zero;
	int	width;
	int	prec;
	int	preca;
	int	i;
	int	length;
}				t_flags;

int				ft_printf(const char *s, ...);
t_flags			ft_analyzer(const char *s, t_flags mine, va_list argp);
t_flags			ft_initialize(void);
t_flags			ft_set_flags(char *s, t_flags mine, va_list argp);
t_flags			ft_print_s(t_flags mine, va_list argp);
t_flags			ft_print_c(t_flags mine, va_list argp);
t_flags			ft_print_id(t_flags mine, va_list argp);
t_flags			ft_len_s(t_flags mine, char *str);
t_flags			xx_ft_print_xx(t_flags mine, va_list argp, char c);
t_flags			ft_print_u(t_flags mine, va_list argp);
t_flags			ft_print_p(t_flags mine, va_list argp);
t_flags			ft_print_percent(t_flags mine);
t_flags			ft_verif(t_flags mine);
int				ft_16(unsigned long int nb);
void			ft_putnbr_base(unsigned long nb,
					char *base, int len, t_flags mine);
void			ft_print_s1(t_flags mine, char *str);
void			ft_print_s0(t_flags mine, char *str);
void			ft_putnbr(long long nb, int prec, int len, t_flags mine);
int				ft_len(char *s);
int				ft_atoi(char *s);
int				ft_isdigit(char c);
int				ft_lgth(long int nb);
void			ft_putchar(char c);
void			ft_putstr(char *s);
void			ft_putnstr(char *s, int n);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzerates <tzerates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:30:11 by tzerates          #+#    #+#             */
/*   Updated: 2020/02/13 15:50:33 by tzerates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	width;
	int	prec;
	int	i;
	int	length;
}				t_flags;

int			ft_printf(const char *s, ...);
t_flags		ft_analyzer(const char *s, t_flags mine, va_list argp);
t_flags		ft_initialize(void);
t_flags		ft_set_flags(char *s, t_flags mine, va_list argp);
t_flags		ft_print_s(t_flags mine, va_list argp);
t_flags		ft_print_c(t_flags mine, va_list argp);
int			ft_len(char *s);
int			ft_atoi(char *s);
int			ft_isdigit(char c);
void		ft_putchar(char c);
void		ft_putstr(char *s);
void		ft_putnstr(char *s, int n);

#endif
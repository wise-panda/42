/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <lbogar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 10:04:00 by lbogar            #+#    #+#             */
/*   Updated: 2018/04/25 21:14:48 by lbo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <string.h>

typedef struct		s_print
{
	size_t			open;
	size_t			close;
	char			type;
	int				hash_flag;
	int				zero_flag;
	int				minus_flag;
	int				plus_flag;
	int				h_len;
	int				hh_len;
	int				l_len;
	int				ll_len;
	int				j_len;
	int				z_len;
	int				empty_flag;
	int				unterminated_flag;
}					t_print;

typedef size_t		(*t_convert)(t_print *flag, va_list *vars);

size_t				ft_convert_int(t_print *flag, va_list *vars);
size_t				ft_convert_octal(t_print *flag, va_list *vars);
size_t				ft_convert_hex(t_print *flag, va_list *vars);
size_t				ft_convert_base(t_print *flag, va_list *vars);
size_t				ft_convert_char(t_print *flag, va_list *vars);
size_t				ft_convert_string(t_print *flag, va_list *vars);
size_t				ft_convert_escape(t_print *flag, va_list *vars);
int					ft_printf_initialize_flag(t_print *flag);
int					ft_printf_assign_flag(const char *format, t_print *flag);
int					ft_printf_scan_input(const char *format, va_list *vars);
int					ft_dispatcher(t_print *flag, va_list *vars);

#endif

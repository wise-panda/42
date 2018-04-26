/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_flag.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbo <lbo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 21:09:43 by lbo               #+#    #+#             */
/*   Updated: 2018/04/25 21:09:49 by lbo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** It recieves the beginning index of the flag and scans for a closing char.
** If it reaches the end of the string - an unterminated flag - it returns (1).
** NOTE: THIS NEEDS TO SUPPORT UNTERMINATED FLAGS WITH WIDTH/PREC
*/

int		ft_printf_close_flag(const char *format, t_print *flag, size_t index)
{
	int		i;
	char	*type;

	type = "sSpdDioOuUxXcC%";
	while (format[index])
	{
		i = 0;
		while (type[i])
		{
			if (format[index] == type[i])
			{
				flag->close = index;
				flag->type = type[i];
				return (0);
			}
			i++;
		}
		index++;
	}
	return (1);
}

/*
** This function should scan the string 'format' for the presence of a modulus.
** If successful, it calls close_flag, to attempt to define flag->open/close.
** If this function reaches the end of the string, it returns (0).
** If close_flag reaches the end of the string, it returnns (2).
*/

int		ft_printf_open_flag(const char *format, t_print *flag)
{
	size_t index;

	index = 0;
	while (format[index])
	{
		if (format[index] == '%')
		{
			flag->open = index;
			if (ft_printf_close_flag(format, flag, (index + 1)))
				return (2);
			return (1);
		}
		index++;
	}
	return (0);
}

/*
** This function detects prefix flag characters between the open and the close
** of a flag, and stores them in the struct as bools. It only counts zeros if
** the preceeding character is not a digit to avoid conflicts with width
** and precision.
*/

int		ft_printf_prefix_parser(const char *format, t_print *flag)
{
	size_t i;

	i = flag->open;
	while (i < flag->close)
	{
		if (format[i] == '#')
			flag->hash_flag = 1;
		if (format[i] == '0' && ft_isdigit(format[i - 1]) == 0)
			flag->zero_flag = 1;
		if (format[i] == '-')
			flag->minus_flag = 1;
		if (format[i] == '+')
			flag->plus_flag = 1;
		if (format[i] == 'j')
			flag->j_len = 1;
		if (format[i] == 'z')
			flag->z_len = 1;
		i++;
	}
	return (0);
}

/*
** This function counts length modifier characters between the open
** and the close of the flag, and increments then into the struct.
*/

int		ft_printf_len_parser(const char *format, t_print *flag)
{
	size_t i;

	i = flag->open;
	while (i < flag->close)
	{
		if (format[i] == 'h' && format[i + 1] != 'h')
			flag->h_len = 1;
		if (format[i] == 'h' && format[i + 1] == 'h')
		{
			flag->hh_len = 1;
			i++;
		}
		if (format[i] == 'l' && format[i + 1] != 'l')
			flag->l_len = 1;
		if (format[i] == 'l' && format[i + 1] == 'l')
		{
			flag->ll_len = 1;
			i++;
		}
		i++;
	}
	return (0);
}

/*
** This function starts by initializing a new flag. It then calls ft_open_flag,
** which sets the open and close of the next flag, and sets the type conversion.
** If the flag is opened, but not terminated, it sets unterm._flag to 1 and
** returns (2). If ft_open_flag reaches the end of the string without finding
** a '%', it returns (0). If if finds a full flag (including a %%), it returns
** (1) and further parses the flag, ID'ing any prefix flags/length modifiers.
*/

int		ft_printf_assign_flag(const char *format, t_print *flag)
{
	int		ret;

	if ((ret = ft_printf_open_flag(format, flag)) == 0)
	{
		free(flag);
		return (0);
	}
	if (ret == 2)
	{
		flag->unterminated_flag = 1;
		return (2);
	}
	ft_printf_prefix_parser(format, flag);
	ft_printf_len_parser(format, flag);
	return (1);
}

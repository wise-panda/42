/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_manage_flag.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbo <lbo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 21:09:07 by lbo               #+#    #+#             */
/*   Updated: 2018/04/25 21:09:18 by lbo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Initialize all the variables in the main struct
*/

int		ft_printf_initialize_flag(t_print *flag)
{
	flag->open = 0;
	flag->close = 0;
	flag->type = '0';
	flag->hash_flag = 0;
	flag->zero_flag = 0;
	flag->minus_flag = 0;
	flag->plus_flag = 0;
	flag->h_len = 0;
	flag->hh_len = 0;
	flag->l_len = 0;
	flag->ll_len = 0;
	flag->j_len = 0;
	flag->z_len = 0;
	flag->empty_flag = 0;
	return (0);
}

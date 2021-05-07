/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 18:43:52 by aapresya          #+#    #+#             */
/*   Updated: 2021/03/06 19:20:17 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFLIB_H
# define PRINTFLIB_H

#include "./libft/libft.h"
#include <stdarg.h>

struct s_flags
{
	int minus;
	int zero;
	int minWidth;
	int period;
	int precision;
	void *arg;
} t_flags;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:14:24 by aapresya          #+#    #+#             */
/*   Updated: 2021/01/26 19:15:51 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	while (((char *)s1)[i] && ((char *)s2)[i] && n > 0)
	{
		if (((char *)s1)[i] != ((char *)s2)[i])
			break ;
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}

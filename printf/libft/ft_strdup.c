/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:24:20 by aapresya          #+#    #+#             */
/*   Updated: 2021/01/26 19:26:09 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	copy = (char *)malloc(i + 1);
	while (i >= 0)
	{
		copy[i] = ((char *)s1)[i];
		i--;
	}
	return (copy);
}

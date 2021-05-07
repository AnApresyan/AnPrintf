/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:43:38 by aapresya          #+#    #+#             */
/*   Updated: 2021/02/02 17:29:16 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ifthereis(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	size_t	start;
	size_t	end;

	start = 0;
	i = 0;
	while (s1[start] && ifthereis(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ifthereis(s1[end - 1], set))
		end--;
	if (!(ptr = (char *)malloc(end - start + 1)))
		return (NULL);
	while (start < end)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}

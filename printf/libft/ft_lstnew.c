/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusaely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 20:04:43 by vmusaely          #+#    #+#             */
/*   Updated: 2021/02/02 20:04:46 by vmusaely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list			*i;

	i = (t_list*)malloc(sizeof(t_list));
	i->content = content;
	i->next = 0;
	return (i);
}

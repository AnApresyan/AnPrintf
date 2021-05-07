/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusaely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:55:08 by vmusaely          #+#    #+#             */
/*   Updated: 2021/02/02 19:55:13 by vmusaely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*n;

	if (*lst)
	{
		n = ft_lstlast(*lst);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*lst = new;
		(*lst)->next = NULL;
	}
}

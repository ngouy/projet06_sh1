/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:59:23 by ngouy             #+#    #+#             */
/*   Updated: 2014/11/26 12:55:34 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*list;

	list = *alst;
	if (!alst || !del)
		return ;
	while (list)
	{
		(*alst) = (*alst)->next;
		ft_lstdelone(&list, del);
		list = *alst;
	}
}

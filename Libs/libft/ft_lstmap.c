/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:57:02 by ngouy             #+#    #+#             */
/*   Updated: 2014/11/25 18:17:10 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*tmp;
	t_list		*tmp2;
	t_list		*ret;

	ret = NULL;
	if (!lst || !f)
		return (ret = malloc(0));
	tmp = lst;
	ft_lstadd(&ret, f(tmp));
	tmp = tmp->next;
	tmp2 = ret;
	while (tmp)
	{
		ft_lstaddend(&tmp2, f(tmp));
		tmp = tmp->next;
	}
	return (ret);
}

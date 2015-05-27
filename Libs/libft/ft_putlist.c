/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 10:09:46 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/24 12:08:53 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_char_list(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_putstr((char *)tmp->content);
		ft_putstr("->");
		tmp = tmp->next;
	}
	ft_putstr("null \n");
}

void	ft_put_int_list(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_putnbr(*((int *)tmp->content));
		ft_putstr("->");
		tmp = tmp->next;
	}
	ft_putstr("null \n");
}

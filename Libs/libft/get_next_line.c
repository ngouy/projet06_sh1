/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 14:31:58 by ngouy             #+#    #+#             */
/*   Updated: 2015/04/03 11:48:36 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_free_fd(t_fd **liste, int fd)
{
	t_fd		*temp;
	t_fd		*temp2;

	if ((*liste)->fd == fd)
	{
		temp = (*liste)->next;
		free(*liste);
		*liste = temp;
		return (0);
	}
	temp = *liste;
	while (temp->next->fd != fd)
		temp = temp->next;
	temp2 = temp->next->next;
	free(temp->next);
	temp->next = temp2;
	return (0);
}

t_fd				*check_n_found(int fd, t_fd **lst)
{
	t_fd	*new;
	t_fd	*liste;
	int		i;

	i = 0;
	liste = *lst;
	while (liste && liste->next)
	{
		if (liste->next->fd == fd)
			return (liste->next);
		liste = liste->next;
	}
	new = (t_fd *)malloc(sizeof(*new));
	new->next = NULL;
	new->fd = fd;
	new->end = 0;
	while (i < BUFF_SIZE)
		new->rest[i++] = '\0';
	if (!*lst)
		*lst = new;
	else
		liste->next = new;
	return (new);
}

int					ft_putrest(t_fd *fd, char **line)
{
	int		i;
	int		j;
	int		ind;
	char	*t;

	i = 0;
	j = i;
	ind = j;
	while (fd->rest[i] && fd->rest[i] != '\n')
	{
		*line = ft_join_free(ft_strjoin(*line,
					t = ft_strsub(fd->rest, i, 1)), *line);
		free(t);
		i++;
	}
	ind = (fd->rest[i] == '\n') ? 1 : 0;
	if (ind == 0 && fd->end == 1)
		fd->end = 2;
	i++;
	while (fd->rest[i])
		fd->rest[j++] = fd->rest[i++];
	while (j != BUFF_SIZE + 1)
		fd->rest[j++] = '\0';
	return (ind);
}

int					rd_n_put(char *buff, char **line, t_fd *liste)
{
	int		ind;
	int		i;
	int		ind2;

	ind2 = 0;
	ind = 1;
	while (ind)
	{
		i = 0;
		ind = (read(liste->fd, buff, BUFF_SIZE));
		if (ind <= 0)
		{
			if (ind2)
				liste->end = 2;
			return (ind);
		}
		buff[ind] = 0;
		while (buff[i++])
			(liste->rest)[i - 1] = buff[i - 1];
		ind2 = 1;
		if (i < BUFF_SIZE && (liste->end = 1))
			return ((ft_putrest(liste, line) + 15 && liste->end == 2) ? 0 : 1);
		ind = ft_putrest(liste, line) - 1;
	}
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	static t_fd		*liste = NULL;
	char			buff[BUFF_SIZE + 1];
	t_fd			*temp;
	int				red;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	buff[BUFF_SIZE] = '\0';
	*line = (char *)malloc(sizeof(char));
	*line[0] = '\0';
	temp = (liste && liste->fd == fd) ? liste : check_n_found(fd, &liste);
	if (ft_putrest(temp, line))
		return (1);
	if ((red = rd_n_put(buff, line, temp)) < 0)
		return (-1);
	if (temp->end == 2)
		return (ft_free_fd(&liste, fd));
	if (red == 0)
	{
		free (*line);
		*line = NULL;
		return (0);
	}
	return (1);
}

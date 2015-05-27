/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 12:34:46 by ngouy             #+#    #+#             */
/*   Updated: 2015/05/27 13:19:53 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Includes/ft_minishell1.h"

void				ft_put_env(char **envp)
{
	int		i;

	i = 0;
	if (!envp)
	{
		ft_putchar('\n');
		return ;
	}
	while (i < NB)
	{
		if (envp[i][0] != '\0')
		{
			ft_putstr(envp[i]);
			ft_putchar('\n');
		}
		i++;
	}
}

void				ft_ctrlc(int i)
{
	(void)i;
	if (g_ii != 1)
	{
		write(1, "\b\b  \n", 5);
		ft_prompt(getcwd(g_pwd, 500));
	}
	else
		write(1, "\n", 1);
}

char				*ft_found(char **envpp, char *tmp, int i)
{
	char		**envp;
	int			j;
	int			k;
	char		*s1;

	k = 1;
	j = 0;
	envp = envpp;
	while (tmp[k])
		k++;
	s1 = (tmp[k - 1] == '=') ? tmp : ft_strjoin(tmp, "=");
	while (*envp && j < NB)
	{
		j++;
		if (ft_strncmp(s1, *envp, ft_strlen(s1)) == 0)
		{
			if (i == 1)
				return (*envp + ft_strlen(s1));
			return (*envp);
		}
		envp++;
	}
	if (tmp[k - 1] != '=')
		free(s1);
	return (NULL);
}

int					ft_check_cd_aux2(char **envp, char **args, int argc)
{
	char		*temp;
	char		*temp2;
	char		*temp3;

	if ((args[1][0] == '-' && args[1][1] == 0) || !ft_strcmp(args[1], "-/"))
	{
		if (!(temp = ft_found(envp, "OLDPWD=", 1)))
			return (ft_printff("sh1 : unable to found OLDPWD\n", NULL, 0));
		if (!(temp2 = ft_found(envp, "PWD=", 1)))
		{
			ft_putstr("sh1 : unable to found PWD\n");
			return (4);
		}
		if ((temp) && access(temp, F_OK) == -1)
			return (ft_printff("sh1 : wrong OLPWD\n", NULL, 0) - 20);
		temp3 = ft_strdup(temp2);
		temp2 = ft_strncpy(temp2, temp, ft_strlen(temp) + 1);
		temp = ft_strncpy(temp, temp3, ft_strlen(temp3) + 1);
		if (temp3)
			free(temp3);
		chdir(temp2);
		return (argc);
	}
	return (0);
}

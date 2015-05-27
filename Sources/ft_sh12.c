/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh12.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 12:35:13 by ngouy             #+#    #+#             */
/*   Updated: 2015/05/27 13:32:06 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Includes/ft_minishell1.h"

static void			ft_set_envaux(char **envp, char **ret, int j, char **tmp)
{
	char		*temp;
	char		*c;

	temp = *tmp;
	ft_strcpy(ret[j], envp[j]);
	if (!ft_strncmp("SHLVL=", ret[j], 6))
	{
		temp = ret[j];
		temp += 6;
		c = ft_itoa(ft_atoi(temp) + 1);
		temp = ft_strcpy(temp, c);
		free(c);
	}
}

char				**ft_set_env(char **envp)
{
	char	**ret;
	int		i;
	int		j;
	int		ind;
	char	*temp;

	i = NB;
	ind = 1;
	j = 0;
	ret = malloc(sizeof(char *) * i + 1);
	while (j < i)
	{
		ret[j] = ft_strnew(LEN);
		if (ind == 1)
		{
			if (!envp || envp[j] == NULL)
				ind = 0;
			else
				ft_set_envaux(envp, ret, j, &temp);
		}
		j++;
	}
	return (ret);
}

void				ft_free_env(char **envp)
{
	int		i;

	i = 0;
	while (i < NB)
	{
		free(envp[i]);
		i++;
	}
	free(envp);
}

int					ft_sub_syscall(char *path, char **args, char **envp)
{
	int		ret;
	pid_t	son;

	if (!ft_strcmp(path, "./ft_minishell1"))
		signal(2, SIG_IGN);
	ret = access(path, F_OK);
	if (ret != 0)
		return (-1);
	ret = access(path, X_OK);
	if (ret != 0)
		return (-1);
	son = fork();
	if (son > 0)
		wait(0);
	if (son == 0)
		ret = execve(path, args, envp);
	if (!ft_strcmp(path, "./ft_minishell1"))
		signal(2, ft_ctrlc);
	return (ret);
}

int					ft_tmp_env(char ***args, int *argc, char ***temp,
		char **envp)
{
	char	*lvl;

	if (!ft_strcmp((*args)[1], "-i"))
	{
		if ((*argc) == 2)
			return (3);
		(*temp) = ft_set_env(NULL);
		(*args)++;
		(*argc)--;
		return (1);
	}
	else
		(*temp) = ft_set_env(envp);
	if ((lvl = ft_found(*temp, "SHLVL=", 1)))
		lvl = ft_strcpy(lvl, ft_itoa(ft_atoi(lvl) - 1));
	return (0);
}

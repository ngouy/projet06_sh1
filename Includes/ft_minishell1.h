/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 10:52:48 by ngouy             #+#    #+#             */
/*   Updated: 2015/04/03 16:05:03 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL1_H

# define FT_MINISHELL1_H
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <dirent.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>

/*
** typedef
*/

typedef struct		s_s1
{
	int				i;
	int				j;
	int				ind;
}					t_s;

/*
** defines
*/
# define P2 "sh1 : setenv: nomore space to set a new variable\n"
# define SB(a, b, c) ft_sub_syscall(a, b, c)
# define DE " permission denied: "
# define GG(a, b) access(a, F_OK) != -1 || b ? DE : " command not found: "
# define P1 "sh1: PATH not found\n"
# define NB 40
# define LEN 200
# define L(a) (ft_strlen(a))

/*
** Globals Variables
*/

int					g_ii;
char				g_pwd[1000];

/*
** Prototypes
*/
void				ft_free_tab(char **tab);
int					ft_printff(char *a, char *b, int i);
char				*ft_fr(char *s1, char *s2, int i);
void				ft_prompt(char *a);
void				ft_put_env(char **envp);
void				ft_ctrlc(int i);
char				*ft_found(char **envp, char *s1, int i);
int					ft_check_cd_aux2(char **envp, char **args, int argc);
int					ft_check_cd_aux1(char **envp, char **args, int argc);
int					ft_check_cd(char **envp, char **args, int argc);
int					ft_check_setenv(char **envp, char **args, int argc);
int					ft_check_unsetenv(char **envp, char **args, int argc);
char				**ft_set_env(char **envp);
void				ft_free_env(char **envp);
int					ft_sub_syscall(char *path, char **args, char **envp);
int					ft_tmp_env(char ***args, int *argc, char ***temp,
		char **envp);
int					ft_check_env(char **envp, char **args, int argc);
int					ft_test_arg0(char *arg0);
int					tt(int argc, char **argv, char **env);
int					ft_argc(char **tab);
void				ft_switch_tab(char **line);
char				**ft_st(char **envp);

#endif

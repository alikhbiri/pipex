/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:01:12 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/01/19 15:20:11 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <libc.h>
# include "../libft/libft.h"

typedef struct s_data
{
	int		pipefd[2];
	int		fd_o;
	int		fd_i;
	int		i;
	int		flag;
	char	**cmd1;
	char	**cmd2;
	char	**s_path;
	int		pid;
	int		pid1;
	int		pid2;
}	t_data;

void	ft_error(int i);
void	ft_free(char **str);
void	cmd2_handle(t_data data, char **av, char **env);
void	cmd1_handle(t_data data, char **av, char **env);
int		exv_cmd(t_data data, char **env, char **cmd);
int		access_exev(t_data data, char **env, char **cmd);
int		check_slash(char **cmd);
char	**make_env(char **env);
char	*find_path(char **env);
void	ft_fork(t_data data, char **av, char **env);
#endif

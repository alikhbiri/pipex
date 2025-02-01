/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:03:54 by alkhbiri          #+#    #+#             */
/*   Updated: 2025/01/17 22:10:36 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int i)
{
	if (i == 1)
		ft_putstr_fd("error\nnumber of args must be 4\n", 2);
	else if (i == 2)
		ft_putstr_fd("command not found\n", 2);
	else if (i == 3)
		ft_putstr_fd("no such file or directory\n", 2);
	else if (i == 0)
		exit(1);
	exit(1);
}

void	ft_free(char **str)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
	str = NULL;
}

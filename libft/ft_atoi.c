/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:57:47 by alkhbiri          #+#    #+#             */
/*   Updated: 2024/11/15 00:45:41 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getsign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	result;
	long long	tmp;

	result = 0;
	sign = 1;
	tmp = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	sign = getsign(&str);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		if (tmp != result / 10 && sign == -1)
			return (0);
		else if (tmp != result / 10 && sign == 1)
			return (-1);
		str++;
		tmp = result;
	}
	return (sign * result);
}

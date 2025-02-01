/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:06:16 by alkhbiri          #+#    #+#             */
/*   Updated: 2024/11/16 16:43:29 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i = 1;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	num;

	num = n;
	len = nbr_len(num);
	str = ft_calloc(len + 1, 1);
	if (!str)
		return (NULL);
	str[len] = 0;
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (len-- > 0 && num != 0)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	if (n == 0)
		str[0] = '0';
	return (str);
}

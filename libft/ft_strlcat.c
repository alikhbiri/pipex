/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:12:21 by alkhbiri          #+#    #+#             */
/*   Updated: 2024/11/16 21:25:19 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(s));
	dst_len = ft_strlen(d);
	src_len = ft_strlen(s);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	i = 0;
	while (s[i] && (i + dst_len + 1) < dstsize)
	{
		d[dst_len + i] = s[i];
		i++;
	}
	if (i + dst_len < dstsize)
		d[dst_len + i] = '\0';
	return (src_len + dst_len);
}

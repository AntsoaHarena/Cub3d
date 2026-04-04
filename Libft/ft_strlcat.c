/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harramar <harramar@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 06:59:54 by harramar          #+#    #+#             */
/*   Updated: 2025/03/25 11:33:46 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	while (dst[i] != '\0')
	{
		i++;
	}
	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	if (size <= i)
		return (len + size);
	j = 0;
	while (src[j] != '\0' && (j < size - i - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + len);
}

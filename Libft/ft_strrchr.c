/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harramar <harramar@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:48:38 by harramar          #+#    #+#             */
/*   Updated: 2025/03/25 11:28:00 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[(int)i] != '\0')
	{
		i++;
	}
	while ((int)i >= 0)
	{
		if (str[(int)i] == (unsigned char)c)
			return (&str[(int)i]);
		i--;
	}
	return (NULL);
}

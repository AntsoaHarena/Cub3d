/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harramar <harramar@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:24:00 by harramar          #+#    #+#             */
/*   Updated: 2025/03/25 11:40:23 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*str1;
	char	*str2;
	size_t	i;
	size_t	j;

	str1 = (char *)s1;
	str2 = (char *)s2;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (str1[i] != '\0')
	{
		str[i + j] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		str[i + j] = str2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

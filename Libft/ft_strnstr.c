/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harramar <harramar@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:38:22 by harramar          #+#    #+#             */
/*   Updated: 2025/03/25 11:30:35 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*bigg;
	size_t	i;
	size_t	j;
	size_t	k;

	bigg = (char *)big;
	if (little[0] == '\0')
		return (bigg);
	k = ft_strlen(little);
	i = 0;
	while (bigg[i] != '\0')
	{
		j = 0;
		if (bigg[i] == little[j])
		{
			while (bigg[i + j] == little[j] && (i + j) < len && little[j])
			{
				j++;
			}
		}
		if (j == k)
			return (&bigg[i]);
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harramar <harramar@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:36:08 by harramar          #+#    #+#             */
/*   Updated: 2025/03/25 11:41:27 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
		{
			i++;
		}
		if (str[i])
		{
			while (str[i] && str[i] != c)
				i++;
			count++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		len;

	str = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (str == NULL)
		return (NULL);
	j = 0;
	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		len = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (len < i)
			str[j++] = ft_substr(s, len, (i - len));
	}
	str[j] = NULL;
	return (str);
}

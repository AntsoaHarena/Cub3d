/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harramar <harramar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 07:39:29 by harramar          #+#    #+#             */
/*   Updated: 2026/04/07 07:55:44 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	count_word(char const *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t')
		{
			i++;
		}
		if (str[i])
		{
			while (str[i] && (str[i] != ' ' || str[i] != '\t'))
				i++;
			count++;
		}
	}
	return (count);
}

char	**split_space_and_tab(char const *s)
{
	char	**str;
	int		i;
	int		j;
	int		len;

	str = (char **)malloc(sizeof(char *) * (count_word(s) + 1));
	if (str == NULL)
		return (NULL);
	j = 0;
	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		len = i;
		while (s[i] != '\0' && (s[i] != ' ' && s[i] != '\t'))
			i++;
		if (len < i)
			str[j++] = ft_substr(s, len, (i - len));
	}
	str[j] = NULL;
	return (str);
}

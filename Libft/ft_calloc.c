/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harramar <harramar@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:07:12 by harramar          #+#    #+#             */
/*   Updated: 2025/03/25 11:31:29 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*ptr;

	i = size * nmemb;
	if (nmemb != 0 && (size != (i / nmemb)))
		return (NULL);
	ptr = malloc(i);
	if (ptr == NULL)
		return (NULL);
	else
		ft_bzero(ptr, i);
	return (ptr);
}

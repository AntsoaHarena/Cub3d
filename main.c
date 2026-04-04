/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harramar <harramar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:51:29 by fanraman          #+#    #+#             */
/*   Updated: 2026/04/03 14:27:07 by fanraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	init_data(&data);
	parsing(fd, &data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harramar <harramar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:10:41 by harramar          #+#    #+#             */
/*   Updated: 2026/04/03 13:48:18 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_texture(char *line)
{
	if (line[0] && line[1] && (line[2] == ' ' || line[2] == '\t'))
		return (1);
	return (0);
}

int	store_data_texture(char **line_split, t_data *data)
{
	char	*path;

	path = ft_strdup(line_split[1]);
	if (ft_strncmp(line_split[0], "NO", 2) == 0 && !data->no)
		data->no = path;
	else if (ft_strncmp(line_split[0], "SO", 2) == 0 && !data->so)
		data->so = path;
	else if (ft_strncmp(line_split[0], "WE", 2) == 0 && !data->we)
		data->we = path;
	else if (ft_strncmp(line_split[0], "EA", 2) == 0 && !data->ea)
		data->ea = path;
	else
	{
		ft_putendl_fd("Error: Duplicate texture identifier or element unknown",
			2);
		free_split(line_split);
		free(path);
		return (0);
	}
	return (1);
}

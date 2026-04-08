/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harramar <harramar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 07:01:25 by harramar          #+#    #+#             */
/*   Updated: 2026/04/07 11:27:04 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_texture(char *line, t_data *data)
{
	char	**line_split;

	line_split = split_space_and_tab(line);
	if (!line_split || !line_split[1] || line_split[2])
	{
		ft_putendl_fd("Error\nInvalid texture format", 2);
		free_split(line_split);
		return (0);
	}
	if (store_data_texture(line_split, data) == 0)
		return (0);
	free_split(line_split);
	return (1);
}

int	parse_color(char *line, t_data *data)
{
	char	**rgb_split;
	char	*color;
	int		rgb[3];

	color = line + 1;
	while (*color == ' ' || *color == '\t')
		color++;
	rgb_split = ft_split(color, ',');
	if (count_comma(color) > 2 || !rgb_split || !rgb_split[0] || !rgb_split[1]
		|| !rgb_split[2] || rgb_split[3])
	{
		ft_putendl_fd("Error\nInvalid color format", 2);
		free_split(rgb_split);
		return (0);
	}
	if (parse_element_color(rgb_split, rgb) == 0)
		return (0);
	if (store_data_color(rgb_split, line, rgb, data) == 0)
		return (0);
	free_split(rgb_split);
	return (1);
}

int	parse_texture_and_color(char *line, char *line_trimmed, t_data *data)
{
	if (line_trimmed == NULL)
	{
		ft_putendl_fd("Error\nMalloc failed", 2);
		return (0);
	}
	if (is_texture(line_trimmed) == 1)
	{
		if (parse_texture(line_trimmed, data) == 0)
		{
			free(line_trimmed);
			return (free(line), 0);
		}
	}
	else if (is_color(line_trimmed) == 1)
	{
		if (parse_color(line_trimmed, data) == 0)
		{
			free(line_trimmed);
			return (free(line), 0);
		}
	}
	return (1);
}

int	parsing(int fd, t_data *data)
{
	char	*line;
	char	*line_trimmed;

	while ((line = get_next_line(fd)))
	{
		line_trimmed = ft_strtrim(line, " \t\n");
		if (*line_trimmed != '\0' && parse_texture_and_color(line, line_trimmed,
				data) == 0)
			return (0);
		if (*line_trimmed != '\0' && is_complete(data) == 1
			&& is_map_line(line_trimmed) == 1)
		{
			data->map_first_line = line;
			return (free(line_trimmed), 1);
		}
		free(line_trimmed);
		free(line);
	}
	if (is_complete(data) == 0)
	{
		ft_putendl_fd("Error\nMissing configuration elements", 2);
		return (0);
	}
	return (1);
}

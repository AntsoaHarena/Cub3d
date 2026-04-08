/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harramar <harramar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:10:51 by harramar          #+#    #+#             */
/*   Updated: 2026/04/07 11:26:27 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_color(char *line)
{
	if ((line[0] == 'F' || line[0] == 'C') && (line[1] == ' '
			|| line[1] == '\t'))
		return (1);
	return (0);
}

int	len_color(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] && str[i] == '0')
		i++;
	while (str[i])
	{
		i++;
		len++;
	}
	return (len);
}

int	parse_element_color(char **rgb_split, int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (is_numeric(rgb_split[i]) == 0)
		{
			ft_putendl_fd("Error\nColor must be numeric and positive", 2);
			return (free_split(rgb_split), 0);
		}
		if (len_color(rgb_split[i]) > 3)
		{
			ft_putendl_fd("Error\nColor range must be [0, 255]", 2);
			return (free_split(rgb_split), 0);
		}
		rgb[i] = ft_atoi(rgb_split[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			ft_putendl_fd("Error\nColor range must be [0, 255]", 2);
			return (free_split(rgb_split), 0);
		}
		i++;
	}
	return (1);
}

int	store_data_color(char **rgb_split, char *line, int *rgb, t_data *data)
{
	int	final_color;

	final_color = ((rgb[0] * 256 * 256) + (rgb[1] * 256) + (rgb[2]));
	if (line[0] == 'F' && data->f_color == -1)
		data->f_color = final_color;
	else if (line[0] == 'C' && data->c_color == -1)
		data->c_color = final_color;
	else
	{
		ft_putendl_fd("Error\nDuplicate color identifier", 2);
		free_split(rgb_split);
		return (0);
	}
	return (1);
}

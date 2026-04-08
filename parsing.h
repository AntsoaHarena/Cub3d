/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harramar <harramar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 07:01:49 by harramar          #+#    #+#             */
/*   Updated: 2026/04/07 11:07:43 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "Libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f_color;
	int		c_color;
	char	*map_first_line;
}			t_data;

void		init_data(t_data *data);
int			parsing(int fd, t_data *data);
int			parse_texture_and_color(char *line, char *line_trimmed,
				t_data *data);
int			parse_color(char *line, t_data *data);
int			parse_texture(char *line, t_data *data);
int			is_texture(char *line);
int			store_data_texture(char **line_split, t_data *data);
int			is_color(char *line);
int			count_comma(char *str);
int			len_color(char *str);
int			parse_element_color(char **rgb_split, int *rgb);
int			store_data_color(char **rgb_split, char *line, int *rgb,
				t_data *data);
void		free_split(char **tab);
int			is_numeric(char *str);
int			is_complete(t_data *data);
int			is_map_line(char *line);
char		**split_space_and_tab(char const *s);

#endif

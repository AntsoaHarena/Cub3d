/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harramar <harramar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:19:09 by harramar          #+#    #+#             */
/*   Updated: 2026/04/02 08:02:02 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *stash);
char	*extract_line(char *stash);
char	*update_stash(char *stash);
char	*ft_strchr1(char *s, char c);
int		ft_strlen1(char *s);
char	*ft_strjoin1(char *s1, char *s2);

#endif

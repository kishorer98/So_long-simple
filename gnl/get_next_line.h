/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:05:01 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/13 12:05:02 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

int			get_next_line(int fd, char **line);
void		*ft_memcpy(void *to, const void *from, size_t numBytes);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);

#endif

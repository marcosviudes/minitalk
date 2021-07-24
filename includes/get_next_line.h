/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:42:25 by mviudes           #+#    #+#             */
/*   Updated: 2020/01/16 21:41:32 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char		*ft_strjoin(char const *s1, char const *s2);
int			get_next_line(int fd, char **line);
void		*ft_memcpy(void *str1, const void *str2, size_t n);
size_t		ft_strlen(const char *s);
size_t		ft_strnlen(const char *s, size_t maxlen);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dest, const char *src, size_t n);
char		*ft_strchr(const char *str, int c);
char		*ft_strcdup(const char *src, int c);
#endif

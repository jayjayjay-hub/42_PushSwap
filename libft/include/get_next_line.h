/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:14:48 by jtakahas          #+#    #+#             */
/*   Updated: 2024/05/07 16:20:50 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include "ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char	*get_next_line(int fd);
size_t	gnl_strlen(const char *str);
char	*gnl_strchr(char *str, int c);
char	*gnl_strjoin(char *str, char *buf);

#endif

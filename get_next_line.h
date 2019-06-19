/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:00:41 by vmcclure          #+#    #+#             */
/*   Updated: 2018/11/30 14:00:45 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 21
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

int	get_next_line(int fd, char **line);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:30:02 by vmcclure          #+#    #+#             */
/*   Updated: 2018/12/09 16:30:03 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_line(int fd, char **line, char **str)
{
	int		i;
	char	*str1;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	*line = ft_strsub(str[fd], 0, i);
	if (str[fd][i] == '\n')
	{
		str1 = ft_strdup(str[fd] + i + 1);
		free(str[fd]);
		str[fd] = str1;
		if (str[fd] == '\0')
		{
			free(str[fd]);
			str[fd] = NULL;
		}
	}
	else if (str[fd][i] == '\0')
	{
		free(str[fd]);
		str[fd] = NULL;
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int			size;
	char		buf[BUFF_SIZE + 1];
	char		*str1;
	static char *str[10241];

	if (fd < 0)
		return (-1);
	while ((size = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[size] = '\0';
		if (!str[fd])
			str[fd] = ft_memalloc(1);
		str1 = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = str1;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (size == 0 && ((!str[fd]) || (str[fd][0] == '\0')))
		return (0);
	if (size < 0)
		return (-1);
	return (ft_line(fd, line, str));
}

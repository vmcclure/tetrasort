/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:44:23 by vmcclure          #+#    #+#             */
/*   Updated: 2018/12/18 15:44:24 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int valid(char **str, int i);

void perevod_v_int(char **str, char i)
{
	int strint[27][9];
	int k;
	int e;
	int b;
	int y;
	int y1;
	int x;
	int x1;
	int m;

	b = 0;
	k = 0;
	e = 0;
	y = 0;
	x = 0;
	y1 = 100;
	x1 = 100;


	while (e < i)
	{
		y1 = 100;
	x1 = 100;
		x = 0;
		y = 0;
		b = 0;
		k = 0;
		while (str[e][k])
		{
			if (str[e][k] == '\n')
				{
				y++;
				k++;
				x = 0;
				}
			if (str[e][k] == '#')
			{	
				if (x1 == 100 && y1 == 100)
				{
					x1 = x;
					y1 = y;					
				}
				m = x - x1;
				//printf("%d\n", m);
				strint[e][b] = m;
				printf("%d", strint[e][b]);
				b++;				
				strint[e][b] = y - y1;
				printf("%d", strint[e][b]);
				b++;
			}
			k++;
			x++;
			
		}
		strint[e][8] = e + 'A';
		printf("%d\n", strint[e][b]);
		e++;	
	}
	//printf("%d", strint[0][0]);
}

int		main(int c, char **v)
{
	int		op;
	char	*str[30];
	char	buf[22];
	int		i;
	int 	e;
	int size;
	int k;

	if (c != 2)
		return (printf("%d", 0));
	k = 0;
	e = 0;
	i = 0;
	op = open(v[1], O_RDONLY);
while (((size = read(op, buf, 21)) > 0) && i < 26)
	{
	if (buf[size] != '\n' && buf[size] != '\0')
		return (printf("%d", 0));
	buf[size] = '\0';
	str[i] = ft_strnew(size);
	str[i] = ft_strncpy(str[i], buf, size);
	i++;
		
	}
	if (i > 26)
		return (printf("%d", 0));
	if (str[i - 1][19] != '\0')
		return (printf("%d", 0));
	while (k < i)
	{
		str[k][19] = '\0';
		k++;
	}
	perevod_v_int(str, i);
	return (printf("%d", valid(str, i)));
}

int valid(char **str, int i)
{
	int e;
	int k;
	int d;
	int m;

	m = 0;
	e = 0;
	k = 0;
	d = 0;
	while (e < i)
	{
		k = 0;
		while(str[e][k])
		{
			if(str[e][k] == '#' )
						m++;	
			if (str[e][k] != '.' && str[e][k] != '#' && str[e][k] != '\n')
			{
				return (0);
			}
				
				if(str[e][k] == '#' && (str[e][k + 1] == '#' || str[e][k + 5] == '#'))
					d++;
				else if (str[e][k] == '#' && str[e][k - 1] == '#' && str[e][k + 4] == '#')
					d++;
				else if (str[e][k] == '#' && (str[e][k - 1] == '#' || str[e][k - 5] == '#'))
					d++;	
					
			k++;
		}
		e++;
	}

	if (m != d)
		return (0);
	if (d == 4 * i)
		return (1);
	return (0);
}
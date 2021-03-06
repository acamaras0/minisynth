/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:28:13 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/27 19:20:43 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sound.h"
#include <fcntl.h>

double ft_notes(char c)
{
	if (c == 'a')
		return (27.50);
	if (c == 'b')
		return (30.87);
	if (c == 'c')
		return (16.35);
	if (c == 'd')
		return (18.35);
	if (c == 'e')
		return (20.60);
	if (c == 'f')
		return (21.83);
	if (c == 'g')
		return (24.50);
	if (c == 'r')
		return (0);
	return (-1);
}

void ft_collect_strc(int argc, char *argv[],  t_instru *tracks[])
{
	int fd;
	char *line;
	int	ret;
	int j = 0;
	int i;
	t_instru *head = NULL;
	int	prev_oct;
	float prev_dur = 0.5;
	int f;
	int k;
	int m = 0;
	int m_count = 0;
	char *temp = NULL;

	if (argc == 1)
	{
		ft_printf("noo arguments dumbo\n");
		return;
	}
	fd = open(argv[1], O_RDONLY);
	if (fd)
	{
		while ((ret = get_next_line(fd, &line)) == 1)
		{
			if (ft_strstr(line, "tempo"))
			{
				f = 0;
				while (line[f] < '0' || line[f] > '9')
					++f;
				f = ft_atoi(&line[f]);
			}
			if (ft_strstr(line, "tracks"))
			{
				while (line[m] != '\0')
				{
					if (line[m] == ',')
						++m_count;
					++m;
				}
				++m_count;
				temp = ft_strdup(ft_strchr(line, ' '));
			}
			if (line[0] >= '0' && line[0] <= '9')
			{
				j = ft_atoi(line) - 1;
				if (tracks[j])
				{
					head = tracks[j];
					while (tracks[j]->next)
					{
						prev_dur = tracks[j]->duration;
						prev_oct = tracks[j]->octa;
						tracks[j] = tracks[j]->next;
					}
					tracks[j]->next = (t_instru *) malloc (sizeof(t_instru));
					//tracks[j] = tracks[j]->next;
				}
				else
				{
					tracks[j] = (t_instru *) malloc (sizeof(t_instru));
					head = tracks[j];
					prev_oct = 4;
					prev_dur = 0.5;
				}
				if (!tracks[j])
				{
					ft_printf("tracks not true\n");
					return;
				}
				tracks[j]->tracks = m;
				tracks[j]->tempo = f;
				i = 0;
				if (temp)
				{
					ft_bzero(tracks[j]->waves, 9);
					strncpy(tracks[j]->waves, temp, ft_strlen_stop(temp, ','));
					while (*temp != ',' && *temp != '\0')
						temp++;
					if (*temp == ',')
						++temp;	
				}
				while (line[i] != '\0')
				{
					tracks[j]->tracks = m_count;
					tracks[j]->tempo = f;
					while ((line[i] < 'a' ||  line[i] > 'g') && line[i] != 'r' && line[i] != '\0')
						++i;
					if (line[i] == '\0')
					{
						tracks[i] = NULL;
						break;
					}
					tracks[j]->pitch = ft_notes(line[i++]);
					if (line[i] == '#' || line[i] == 'b')
					{
						if (line[i] == '#')
							tracks[j]->flat_sharp = 1;
						else
							tracks[j]->flat_sharp = 2;
						++i;
					}
					else
						tracks[j]->flat_sharp = 0;
					if (line[i] >= '0' && line[i] <= '9')
					{
						tracks[j]->octa = ft_atoi(&line[i]);
						prev_oct = ft_atoi(&line[i]);
						++i;
					}
					else
						tracks[j]->octa = prev_oct;
					if (line[i] == '/')
					{
						++i;
						tracks[j]->duration = atof(&line[i]);
						prev_dur = atof(&line[i]);
					}
					else
						tracks[j]->duration = prev_dur;
					while ((line[i] >= '0' && line[i] <= '9') || line[i] == '.')
						++i;
					if (line[i] == '\0')
					{
						tracks[j]->next = NULL;
						break ;
					}
					tracks[j]->next = (t_instru *) malloc (sizeof(t_instru));
					ft_strcpy(tracks[j]->next->waves, tracks[j]->waves);
					if (!tracks[j]->next)
					{
						ft_printf("problem\n");
						return;
					}
					tracks[j] = tracks[j]->next;
					++i;
				}
				tracks[j] = NULL;
				tracks[j] = head;
				++j;
			}
		}
	}
}

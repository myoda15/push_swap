/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 00:00:00 by mande-so          #+#    #+#             */
/*   Updated: 2026/01/21 01:45:51 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	buffer[2];
	int		i;
	int		bytes;

	line = malloc(1000);
	if (!line)
		return (NULL);
	i = 0;
	bytes = read(fd, buffer, 1);
	while (bytes > 0)
	{
		buffer[1] = '\0';
		line[i++] = buffer[0];
		if (buffer[0] == '\n')
			break ;
		bytes = read(fd, buffer, 1);
	}
	line[i] = '\0';
	if (bytes <= 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_reader_map_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:45:46 by aprivalo          #+#    #+#             */
/*   Updated: 2025/12/29 07:16:15 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char **ft_reader_map(int fd)
{
	char *line;
	char *init_map;
	char *tmp_map;
	char **map;

	init_map = NULL;
	map = NULL;
	tmp_map = ft_calloc(1, sizeof(char));
	if (!tmp_map)
		return (NULL);
	while ((line = get_next_line(fd)) != NULL)
	{
		init_map = ft_strjoin(tmp_map, line);
		free(line);
		free(tmp_map);
		tmp_map = init_map;
	}
	map = ft_split(init_map, '\n');
	free(init_map);
	return (map);
}

void ft_prepare_map(void)
{
	int fd;
	char **map;

	map = NULL;
	fd = open("./maps/map.ber", O_RDONLY);
	if (fd < 0 || fd > 1024)
	{
		perror("File map .ber not found or wrong format !");
		return ;
	}
	map = ft_reader_map(fd);
	ft_checker_map(map);
	ft_free_map(map);
	close(fd);
}

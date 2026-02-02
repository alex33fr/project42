/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_read_prepare_map_fd.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:45:46 by aprivalo          #+#    #+#             */
/*   Updated: 2026/01/29 15:37:20 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_has_empty_line(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' && s[i + 1] == '\n' && s[i + 2] != '\0')
			return (1);
		i++;
	}
	return (0);
}

static char	**ft_reader_map(int fd)
{
	char	*line;
	char	*init_map;
	char	*tmp_map;
	char	**map;

	init_map = NULL;
	tmp_map = ft_calloc(1, sizeof(char));
	if (!tmp_map)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		init_map = ft_strjoin(tmp_map, line);
		free(line);
		free(tmp_map);
		if (!init_map)
			return (NULL);
		tmp_map = init_map;
		line = get_next_line(fd);
	}
	if (!init_map || ft_has_empty_line(init_map))
	{
		free(init_map);
		return (NULL);
	}
	map = ft_split(init_map, '\n');
	free(init_map);
	return (map);
}

char	**ft_prepare_map(char *filename)
{
	int		fd;
	char	*file;
	char	**map;

	if (!ft_has_ber_extension(filename))
		return (NULL);
	file = ft_strjoin("maps/", filename);
	if (!file)
		return (NULL);
	fd = open(file, O_RDONLY);
	free(file);
	if (fd < 0)
		return (NULL);
	map = ft_reader_map(fd);
	close(fd);
	if (!map)
		return (NULL);
	if (!ft_checker_map(map))
	{
		ft_free_map(map);
		return (NULL);
	}
	return (map);
}

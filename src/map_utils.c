/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:15:41 by vipalaci          #+#    #+#             */
/*   Updated: 2023/06/26 11:30:56 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	read_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		return (ft_error("Error: error reading from file\n"));
	line = get_next_line(fd);
	if (!line)
		return (ft_error("Error: empty map!\n"));
	game->map.height = 0;
	game->map.width = ft_strlen(line) - 1;
	game->map.line = ft_strdup_no_nl(line);
	free(line);
	while (line)
	{
		game->map.height++;
		line = get_next_line(fd);
		if (line)
			game->map.line = ft_strjoin_no_nl(game->map.line, line);
		free(line);
	}
	close(fd);
	if ((game->map.height * game->map.width) != (int)ft_strlen(game->map.line))
		return (ft_error("Error: map is not rectangular\n"));
	return (1);
}

int	create_layout(t_game *game)
{
	int	h;
	int	w;
	int	i;

	i = 0;
	h = 0;
	game->map.lay = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.lay)
		return (0);
	while (h < game->map.height)
	{
		w = 0;
		game->map.lay[h] = malloc(sizeof(char) * game->map.width);
		if (!game->map.lay[h])
			return (0);
		while (w < game->map.width)
			game->map.lay[h][w++] = game->map.line[i++];
		game->map.lay[h][w] = '\0';
		h++;
	}
	game->map.lay[h] = 0;
	return (1);
}

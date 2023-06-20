/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:03:23 by vipalaci          #+#    #+#             */
/*   Updated: 2023/06/20 17:01:13 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	check_path(t_game *game)
{
	int	e;
	int	h;
	int	w;

	h = 0;
	while (h < game->map.height)
	{
		w = 0;
		while (w < game->map.width)
		{
			if (game->map.lay[h][w] == 'P')
				break ;
			w++;
		}
		if (game->map.lay[h][w] == 'P')
			break ;
		h++;
	}
}

int	check_walls(t_game *game)
{
	int	h;
	int	w;

	w = 0;
	while (game->map.lay[0][w])
		if (game->map.lay[0][w++] != '1')
			return (ft_error("Error: map is not surrounded by walls\n"));
	h = 1;
	while (game->map.lay[h] < game->map.lay[game->map.height - 1])
	{
		if (game->map.lay[h][0] != '1' ||
			game->map.lay[h][game->map.width - 1] != '1')
			return (ft_error("Error: map is not surrounded by walls\n"));
		h++;
	}
	w = 0;
	while (game->map.lay[game->map.height - 1][w])
		if (game->map.lay[game->map.height - 1][w++] != '1')
			return (ft_error("Error: map is not surrounded by walls\n"));
	return (1);
}

int	check_elements(t_game *game)
{
	int	i;
	int	e;
	int	c;
	int	p;

	i = 0;
	e = 0;
	c = 0;
	p = 0;
	while (game->map.line[i])
	{
		if (game->map.line[i] == 'E')
			e += 1;
		if (game->map.line[i] == 'C')
			c += 1;
		if (game->map.line[i] == 'P')
			p += 1;
		i++;
	}
	if (e != 1 || c < 1 || p != 1)
		return (ft_error("Error: incorrect number of elements\n"));
	game->chest_count = 0;
	game->chest_total = c;
	game->p.steps = 0;
	return (1);
}

int	check_input(int argc, char **argv)
{
	if (argc != 2)
		return (ft_error("Error: incorrect number of arguments\n"));
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		return (ft_error("Error: incorrect file extension\n"));
	return (1);
}

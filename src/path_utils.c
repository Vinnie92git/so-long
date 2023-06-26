/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:02:47 by vipalaci          #+#    #+#             */
/*   Updated: 2023/06/26 16:00:24 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_floodfill(t_game *game, int h, int w)
{
	if (game->map.cpy[h][w] == '1' || game->map.cpy[h][w] == 'F'
		|| game->map.cpy[h][w] == 'E')
		return ;
	game->map.cpy[h][w] = 'F';
	ft_floodfill(game, h + 1, w);
	ft_floodfill(game, h - 1, w);
	ft_floodfill(game, h, w + 1);
	ft_floodfill(game, h, w - 1);
	return ;
}

void	find_start(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	while (h < game->map.height)
	{
		w = 0;
		while (w < game->map.width)
		{
			if (game->map.cpy[h][w] == 'P')
				break ;
			w++;
		}
		if (game->map.cpy[h][w] == 'P')
			break ;
		h++;
	}
	ft_floodfill(game, h, w);
}

void	copy_layout(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	game->map.cpy = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.cpy)
		return ;
	while (h < game->map.height)
	{
		w = 0;
		game->map.cpy[h] = malloc(sizeof(char) * game->map.width);
		if (!game->map.cpy[h])
			return ;
		while (w < game->map.width)
		{
			game->map.cpy[h][w] = game->map.lay[h][w];
			w++;
		}
		game->map.cpy[h][w] = '\0';
		h++;
	}
	game->map.cpy[h] = 0;
}

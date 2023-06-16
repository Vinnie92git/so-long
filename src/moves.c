/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:36:42 by vipalaci          #+#    #+#             */
/*   Updated: 2023/06/16 15:21:25 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	key_event(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	if (key_code == KEY_W)
		move_up(game);
	if (key_code == KEY_A)
		move_left(game);
	if (key_code == KEY_S)
		move_down(game);
	if (key_code == KEY_D)
		move_right(game);
	return (0);
}

/* void	update_map(t_game *game, int h, int w)
{
	if (game->map.lay[h + 1][w] != '1' && game->map.lay[h + 1][w] != 'E')
	{
		game->map.lay[h][w] = '0';
		game->map.lay[h + 1][w] = 'P';
		build_map(game, game->mlx, game->window);
	}
} */

void	move_up(t_game *game)
{
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
	if (game->map.lay[h + 1][w] != '1' && game->map.lay[h + 1][w] != 'E')
	{
		game->map.lay[h][w] = '0';
		game->map.lay[h + 1][w] = 'P';
		build_map(game, game->mlx, game->window);
	}
}

void 	move_down(t_game *game)
{
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
	if (game->map.lay[h + 1][w] != '1' && game->map.lay[h + 1][w] != 'E')
	{
		game->map.lay[h][w] = '0';
		game->map.lay[h + 1][w] = 'P';
		build_map(game, game->mlx, game->window);
	}
}

void 	move_left(t_game *game)
{
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
	if (game->map.lay[h][w - 1] != '1' && game->map.lay[h][w - 1] != 'E')
	{
		game->map.lay[h][w] = '0';
		game->map.lay[h][w - 1] = 'P';
		build_map(game, game->mlx, game->window);
	}
}

void 	move_right(t_game *game)
{
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
	if (game->map.lay[h][w + 1] != '1' && game->map.lay[h][w + 1] != 'E')
	{
		game->map.lay[h][w] = '0';
		game->map.lay[h][w + 1] = 'P';
		build_map(game, game->mlx, game->window);
	}
}

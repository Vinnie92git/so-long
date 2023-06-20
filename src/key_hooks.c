/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:36:42 by vipalaci          #+#    #+#             */
/*   Updated: 2023/06/19 16:08:37 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	key_event(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	if (key_code == KEY_W || key_code == ARROW_UP)
		key_up(game);
	if (key_code == KEY_A || key_code == ARROW_LEFT)
		key_left(game);
	if (key_code == KEY_S || key_code == ARROW_DOWN)
		key_down(game);
	if (key_code == KEY_D || key_code == ARROW_RIGHT)
		key_right(game);
	return (0);
}

void	key_up(t_game *game)
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
	move_up(game, h, w);
}

void	key_down(t_game *game)
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
	move_down(game, h, w);
}

void	key_left(t_game *game)
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
	move_left(game, h, w);
}

void	key_right(t_game *game)
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
	move_right(game, h, w);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:00:12 by vipalaci          #+#    #+#             */
/*   Updated: 2023/06/20 17:10:02 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	move_up(t_game *game, int h, int w)
{
	if (game->map.lay[h - 1][w] != '1' && game->map.lay[h - 1][w] == 'D' &&
		game->chest_count == game->chest_total)
	{
		ft_printf("You escaped the dungeon!\n");
		exit(0);
	}
	if (game->map.lay[h - 1][w] != '1' && game->map.lay[h - 1][w] != 'E')
	{
		if (game->map.lay[h - 1][w] == 'C')
			game->chest_count += 1;
		if (game->chest_count == game->chest_total)
			open_exit(game);
		game->p.steps += 1;
		ft_printf("Total moves: %d\n", game->p.steps);
		game->map.lay[h][w] = '0';
		game->map.lay[h - 1][w] = 'P';
		build_map(game);
	}
}

void	move_down(t_game *game, int h, int w)
{
	if (game->map.lay[h + 1][w] != '1' && game->map.lay[h + 1][w] == 'D' &&
		game->chest_count == game->chest_total)
	{
		ft_printf("You escaped the dungeon!\n");
		exit(0);
	}
	if (game->map.lay[h + 1][w] != '1' && game->map.lay[h + 1][w] != 'E')
	{
		if (game->map.lay[h + 1][w] == 'C')
			game->chest_count += 1;
		if (game->chest_count == game->chest_total)
			open_exit(game);
		game->p.steps += 1;
		ft_printf("Total moves: %d\n", game->p.steps);
		game->map.lay[h][w] = '0';
		game->map.lay[h + 1][w] = 'P';
		build_map(game);
	}
}

void	move_left(t_game *game, int h, int w)
{
	if (game->map.lay[h][w - 1] != '1' && game->map.lay[h][w - 1] == 'D' &&
		game->chest_count == game->chest_total)
	{
		ft_printf("You escaped the dungeon!\n");
		exit(0);
	}
	if (game->map.lay[h][w - 1] != '1' && game->map.lay[h][w - 1] != 'E')
	{
		if (game->map.lay[h][w - 1] == 'C')
			game->chest_count += 1;
		if (game->chest_count == game->chest_total)
			open_exit(game);
		game->p.steps += 1;
		ft_printf("Total moves: %d\n", game->p.steps);
		game->map.lay[h][w] = '0';
		game->map.lay[h][w - 1] = 'P';
		build_map(game);
	}
}

void	move_right(t_game *game, int h, int w)
{
	if (game->map.lay[h][w + 1] != '1' && game->map.lay[h][w + 1] == 'D' &&
		game->chest_count == game->chest_total)
	{
		ft_printf("You escaped the dungeon!\n");
		exit(0);
	}
	if (game->map.lay[h][w + 1] != '1' && game->map.lay[h][w + 1] != 'E')
	{
		if (game->map.lay[h][w + 1] == 'C')
			game->chest_count += 1;
		if (game->chest_count == game->chest_total)
			open_exit(game);
		game->p.steps += 1;
		ft_printf("Total moves: %d\n", game->p.steps);
		game->map.lay[h][w] = '0';
		game->map.lay[h][w + 1] = 'P';
		build_map(game);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:19:12 by vipalaci          #+#    #+#             */
/*   Updated: 2023/07/10 18:05:10 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	open_exit(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	while (h < game->map.height)
	{
		w = 0;
		while (w < game->map.width)
		{
			if (game->map.lay[h][w] == 'E')
				game->map.lay[h][w] = 'D';
			w++;
		}
		h++;
	}
}

void	put_images(t_game *game, int h, int w)
{
	if (game->map.lay[h][w] == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->map.w, w * 32, h * 32);
	else if (game->map.lay[h][w] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->map.c, w * 32, h * 32);
	else if (game->map.lay[h][w] == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			game->p.r, w * 32, h * 32);
	else if (game->map.lay[h][w] == 'L')
		mlx_put_image_to_window(game->mlx, game->window,
			game->p.l, w * 32, h * 32);
	else if (game->map.lay[h][w] == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->map.e, w * 32, h * 32);
	else if (game->map.lay[h][w] == 'D')
		mlx_put_image_to_window(game->mlx, game->window,
			game->map.d, w * 32, h * 32);
	else
		mlx_put_image_to_window(game->mlx, game->window,
			game->map.f, w * 32, h * 32);
}

void	set_images(t_game *game)
{
	int	height;
	int	width;

	game->map.f = mlx_xpm_file_to_image(game->mlx,
			"./imgs/floor.xpm", &width, &height);
	game->map.w = mlx_xpm_file_to_image(game->mlx,
			"./imgs/wall.xpm", &width, &height);
	game->map.c = mlx_xpm_file_to_image(game->mlx,
			"./imgs/chest.xpm", &width, &height);
	game->map.e = mlx_xpm_file_to_image(game->mlx,
			"./imgs/exit_closed.xpm", &width, &height);
	game->map.d = mlx_xpm_file_to_image(game->mlx,
			"./imgs/exit_open.xpm", &width, &height);
	game->p.r = mlx_xpm_file_to_image(game->mlx,
			"./imgs/player.xpm", &width, &height);
	game->p.l = mlx_xpm_file_to_image(game->mlx,
			"./imgs/player_left.xpm", &width, &height);
	if (!game->map.f || !game->map.w || !game->map.c
		|| !game->map.e || !game->map.d || !game->p.r || !game->p.l)
	{
		ft_error("Error: unable to find image/s\n");
		exit (1);
	}
}

void	build_map(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	while (h < game->map.height)
	{
		w = 0;
		while (w < game->map.width)
		{
			put_images(game, h, w);
			w++;
		}
		h++;
	}
}

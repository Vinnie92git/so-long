/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:19:12 by vipalaci          #+#    #+#             */
/*   Updated: 2023/06/16 15:15:46 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	put_images(t_game *game, void *mlx, void *win, int h, int w)
{
	if (game->map.lay[h][w] == '1')
		mlx_put_image_to_window(mlx, win, game->map.w, w * 32, h * 32);
	else if (game->map.lay[h][w] == 'C')
		mlx_put_image_to_window(mlx, win, game->map.c, w * 32, h * 32);
	else if (game->map.lay[h][w] == 'O')
		mlx_put_image_to_window(mlx, win, game->map.o, w * 32, h * 32);
	else if (game->map.lay[h][w] == 'P')
		mlx_put_image_to_window(mlx, win, game->p.r, w * 32, h * 32);
	else if (game->map.lay[h][w] == 'L')
		mlx_put_image_to_window(mlx, win, game->p.l, w * 32, h * 32);
	else if (game->map.lay[h][w] == 'E')
		mlx_put_image_to_window(mlx, win, game->map.d, w * 32, h * 32);
	else if (game->map.lay[h][w] == 'D')
		mlx_put_image_to_window(mlx, win, game->map.e, w * 32, h * 32);
	else
		mlx_put_image_to_window(mlx, win, game->map.f, w * 32, h * 32);
}

void	set_images(t_game *game, void *mlx)
{
	int	height;
	int	width;

	game->map.f = mlx_xpm_file_to_image(mlx, 
						"./imgs/floor.xpm", &width, &height);
	game->map.w = mlx_xpm_file_to_image(mlx, 
						"./imgs/wall.xpm", &width, &height);
	game->map.c = mlx_xpm_file_to_image(mlx, 
						"./imgs/chest.xpm", &width, &height);
	game->map.o = mlx_xpm_file_to_image(mlx, 
						"./imgs/chest_open.xpm", &width, &height);
	game->map.d = mlx_xpm_file_to_image(mlx, 
						"./imgs/door.xpm", &width, &height);
	game->map.e = mlx_xpm_file_to_image(mlx, 
						"./imgs/door_open.xpm", &width, &height);
	game->p.r = mlx_xpm_file_to_image(mlx, 
						"./imgs/player.xpm", &width, &height);
	game->p.l = mlx_xpm_file_to_image(mlx, 
						"./imgs/player_left.xpm", &width, &height);
}

void	build_map(t_game *game, void *mlx, void *win)
{
	int	h;
	int	w;

	h = 0;
	while (h < game->map.height)
	{
		w = 0;
		while (w < game->map.width)
		{
			put_images(game, mlx, win, h, w);
			w++;
		}
		h++;
	}
}

void	create_layout(t_game *game)
{
	int	h;
	int	w;
	int	i;
	
	i = 0;
	h = 0;
	game->map.lay = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.lay)
		return ;
	while (h < game->map.height)
	{
		w = 0;
		game->map.lay[h] = malloc(sizeof(char) * ft_strlen(game->map.line));
		if (!game->map.lay[h])
			return ;
		while (w < game->map.width)
		{
			game->map.lay[h][w] = game->map.line[i];
			w++;
			i++;
		}
		game->map.lay[h][w] = '\0';
		h++;
	}
	game->map.lay[h] = 0;
}

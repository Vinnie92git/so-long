/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:47:09 by vipalaci          #+#    #+#             */
/*   Updated: 2023/06/26 16:09:26 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	red_x(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit (0);
}

int	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->window = mlx_new_window(game->mlx, game->map.width * 32,
			game->map.height * 32, "ESCAPE THE DUNGEON!");
	if (!game->window)
		return (0);
	return (1);
}

int	start_game(char **argv, t_game *game)
{
	if (!read_map(argv[1], game) || !check_elements(game)
		|| !create_layout(game) || !check_path(game)
		|| !check_walls(game) || !init_window(game))
	{
		ft_free(game->map.lay);
		ft_free(game->map.cpy);
		free(game->map.line);
		return (0);
	}
	game->chest_count = 0;
	game->p.steps = 0;
	set_images(game);
	build_map(game);
	return (1);
}

void	leaks(void)
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	t_game	game;

	atexit(leaks);
	if (!check_input(argc, argv) || !start_game(argv, &game))
		return (1);
	mlx_hook(game.window, X_EVENT_KEY_PRESS, 0, &key_event, &game);
	mlx_hook(game.window, X_EVENT_KEY_EXIT, 0, &red_x, &game);
	mlx_loop(game.mlx);
	return (0);
}

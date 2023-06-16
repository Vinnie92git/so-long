/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:47:09 by vipalaci          #+#    #+#             */
/*   Updated: 2023/06/16 14:53:37 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	red_x(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit (0);
}

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
	}
	close(fd);
	return (1);
}

int	check_extension(char *filename, char *extension)
{
	if (!ft_strnstr(filename, extension, ft_strlen(filename)))
		return (0);
	return (1);
}

int	start_game(char **argv, t_game *game)
{
	if (!check_extension(argv[1], ".ber"))
		return (ft_error("Error: incorrect file extension\n"));
	read_map(argv[1], game);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->window = mlx_new_window(game->mlx, game->map.width * 32, 
					game->map.height * 32, "so_long");
	if (!game->window)
		return (0);
	set_images(game, game->mlx);
	create_layout(game);
	build_map(game, game->mlx, game->window);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;
	
	if (argc != 2)
		return (ft_error("Error: incorrect number of arguments\n"));
	if (!start_game(argv, &game))
		return (1);
	mlx_hook(game.window, X_EVENT_KEY_PRESS, 0, &key_event, &game);
	mlx_hook(game.window, X_EVENT_KEY_EXIT, 0, &red_x, &game);
	mlx_loop(game.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:47:09 by vipalaci          #+#    #+#             */
/*   Updated: 2023/06/08 14:56:36 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	read_map(char *filename)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		return (ft_error("Error: error reading from file\n"));
	line = get_next_line(fd);
	if (!line)
		return (ft_error("Error: empty map!\n"));
	close(fd);
	return (1);
}

int	check_extension(char *filename, char *extension)
{
	if (!ft_strnstr(filename, extension, ft_strlen(filename)))
		return (0);
	return (1);
}

int	start_game(int argc, char **argv)
{
	if (argc != 2)
		return (ft_error("Error: incorrect number of arguments\n"));
	if (!check_extension(argv[1], ".ber"))
		return (ft_error("Error: incorrect file extension\n"));
	read_map(argv[1]);
	return (1);
}

int	main(int argc, char **argv)
{
	// t_game	game;
	
	if (!start_game(argc, argv))
		return (1);
	return (0);
	
	// void	*mlx;
	// void	*mlx_win;

	// mlx = mlx_init();
	// if (!mlx)
	// 	return (1);
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	// if (!mlx_win)
	// 	return (2);
	// mlx_loop(mlx);
	// return (0);	
}

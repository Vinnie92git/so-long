/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:26:20 by vipalaci          #+#    #+#             */
/*   Updated: 2023/06/08 14:54:24 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include <mlx.h>
# include <fcntl.h>

typedef struct s_player
{
	int		pos;
	void	*facing_up;
	void	*facing_down;
	void	*facing_left;
	void	*facing_right;
}	t_player;

typedef struct s_map
{
	char	*map_line;
	char	**map_layout;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_map		map;
	t_player	player;
}	t_game;

int	check_extension(char *filename, char *extension);
int	start_game(int argc, char **argv);
int	ft_error(char *message);
int	read_map(char *filename);

#endif
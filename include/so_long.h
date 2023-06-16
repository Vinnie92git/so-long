/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:26:20 by vipalaci          #+#    #+#             */
/*   Updated: 2023/06/16 15:19:32 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT 			17

# define KEY_ESC					53
# define KEY_W						13
# define KEY_A						0
# define KEY_S						1
# define KEY_D						2

typedef struct s_player
{
	int		steps;
	void	*l;
	void	*r;
}	t_player;

typedef struct s_map
{
	int		height;
	int		width;
	char	*line;
	char	**lay;
	void	*f;
	void	*w;
	void	*c;
	void	*o;
	void	*d;
	void	*e;
}	t_map;

typedef struct s_game
{
	int			col_count;
	int			col_total;
	void		*mlx;
	void		*window;
	t_map		map;
	t_player	p;
}	t_game;

int		check_extension(char *filename, char *extension);
int		start_game(char **argv, t_game *game);
int		ft_error(char *message);
int		read_map(char *filename, t_game *game);
int		key_event(int key_code, t_game *game);

char	*ft_strdup_no_nl(char *str);
char	*ft_strjoin_no_nl(char *s1, char *s2);

void	ft_free(char **s);
void	create_layout(t_game *game);
void	set_images(t_game *game, void *mlx);
void	build_map(t_game *game, void *mlx, void *win);
void	put_images(t_game *game, void *mlx, void *win, int h, int w);
void	update_map(t_game *game, int h, int w);
void 	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

#endif
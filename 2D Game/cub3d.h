/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:42:55 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/29 10:24:29 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <math.h>

typedef struct t_player
{
	float			p_x;
	float			p_y;
	float			ln_x;
	float			ln_y;
	int				turn_drct;
	float			rotation_angel;
}	t_ply;

typedef struct t_rs
{
	float		ray_angle;
	double		fov;
	float		increment;
	float		ah_x;
	float		ah_y;
	float		av_x;
	float		av_y;
}   t_ray;

typedef struct t_dat
{
	int		height;
	int		width;
	mlx_image_t	*image;
	char	*str[12];
	void	*mlx;
	void	*window;
	t_ply	player;
	t_ray	ray;
}	t_data;

void	ft_textures(t_data *data);
int		ft_destroy(t_data *data);
void	ft_event(void *dat);
void	ft_end(int sig);
void	ft_draw_map(t_data *data);
void	ft_abort(int id);
char	*ft_strdup(char *s1);
void	ft_draw_player(t_data *data);
int		ft_check_wall(t_data *data, int x, int y);
float	ft_find_distance(t_data *data, float x, float y);
int		ft_strlen(char *s);

#endif
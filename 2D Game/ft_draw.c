/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 12:47:06 by idabligi          #+#    #+#             */
/*   Updated: 2023/06/19 10:53:53 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//----------------------------------------------------------------------------//

void	ft_draw_line(t_data *data)
{
	data->player.ln_x = data->player.p_x + cos(data->player.rotation_angel) * 20;
	data->player.ln_y = data->player.p_y + sin(data->player.rotation_angel) * 20;
	mlx_put_pixel(data->image, data->player.ln_x, data->player.ln_y, 0x00000000);
}

//----------------------------------------------------------------------------//

void    ft_draw_player(t_data *data)
{
	mlx_put_pixel(data->image, data->player.p_x - 1, data->player.p_y, 0x00000000);
	mlx_put_pixel(data->image, data->player.p_x, data->player.p_y - 1, 0x00000000);
	mlx_put_pixel(data->image, data->player.p_x, data->player.p_y, 0x00000000);
	mlx_put_pixel(data->image, data->player.p_x, data->player.p_y + 1, 0x00000000);
	mlx_put_pixel(data->image, data->player.p_x + 1, data->player.p_y, 0x00000000);
}
//----------------------------------------------------------------------------//

void    ft_color(t_data *data, int x, int y)
{
	int i;
	int j;
	int s;

	i = 0;
	j = 0;
	s = x;
	while (j < 49)
	{
		i = 0;
		x = s;
		while (i < 49)
		{
			mlx_put_pixel(data->image, x, y, 0x00CCFFFFFF);
			x++;
			i++;
		}
		y++;
		j++;
	}
}

//----------------------------------------------------------------------------//

void	ft_draw_intersection(t_data *data, float ax, float ay)
{
	float	distance;

	distance = ft_find_distance(data, ax, ay);
	while (distance > 0)
	{
		ax = data->player.p_x + cos(data->ray.ray_angle) * floor(distance);
		ay = data->player.p_y + sin(data->ray.ray_angle) * floor(distance);
		mlx_put_pixel(data->image, ax, ay, 0x0000FF00FF);
		distance--;
	}
}

//----------------------------------------------------------------------------//

float	ft_find_hr(t_data *data)
{
	float		j = 0;
	float	dt_x = 0;
	float	dt_y = 0;


	if (data->ray.ray_angle > 0 && data->ray.ray_angle < M_PI)
		data->ray.ah_y = floor(data->player.p_y / 50) * 50 + 50;
	else
	{
		data->ray.ah_y = floor(data->player.p_y / 50) * 50;
		j = -0.01;
	}
	
	data->ray.ah_x = data->player.p_x + ((data->ray.ah_y - data->player.p_y) / tan(data->ray.ray_angle));
	dt_y = 50;
	dt_x = dt_y / tan(data->ray.ray_angle);
	while (!ft_check_wall(data, data->ray.ah_x, data->ray.ah_y + j))
	{
		if (j)
		{
			data->ray.ah_x -= dt_x;
			data->ray.ah_y -= dt_y;
		}
		else
		{
			data->ray.ah_x += dt_x;
			data->ray.ah_y += dt_y;
		}
	}
	return (ft_find_distance(data, data->ray.ah_x, data->ray.ah_y));
}

//----------------------------------------------------------------------------//

float	ft_find_vr(t_data *data)
{
	float	j = 0;
	float	dt_x = 0;
	float	dt_y = 0;

	if (data->ray.ray_angle <= (M_PI/2) || data->ray.ray_angle >= ((3*M_PI) / 2))
		data->ray.av_x = floor(data->player.p_x / 50) * 50 + 50;
	else
	{
		data->ray.av_x = floor(data->player.p_x / 50) * 50;
		j = -0.01;
	}
	data->ray.av_y = data->player.p_y + ((data->ray.av_x - data->player.p_x) * tan(data->ray.ray_angle));
	dt_x = 50;
	dt_y = dt_x * tan(data->ray.ray_angle);
	while (!ft_check_wall(data, data->ray.av_x + j, data->ray.av_y))
	{
		if (j)
		{
			data->ray.av_x -= dt_x;
			data->ray.av_y -= dt_y;
		}
		else
		{
			data->ray.av_x += dt_x;
			data->ray.av_y += dt_y;
		}
	}
	return (ft_find_distance(data, data->ray.av_x, data->ray.av_y));
}

//----------------------------------------------------------------------------//

void	ft_draw_fov(t_data *data)
{
	int		i = 0;

	data->ray.ray_angle = data->player.rotation_angel - (data->ray.fov / 2);
	while (i < 750)
	{
		if (data->ray.ray_angle < 0)
			data->ray.ray_angle += 2 * M_PI;

		if (data->ray.ray_angle >= 2 * M_PI)
			data->ray.ray_angle -= 2 * M_PI;

		if (ft_find_hr(data) < ft_find_vr(data))
			ft_draw_intersection(data, data->ray.ah_x, data->ray.ah_y);
		else
			ft_draw_intersection(data, data->ray.av_x, data->ray.av_y);
		data->ray.ray_angle += data->ray.increment;
		i++;
	}
}

//----------------------------------------------------------------------------//

void	ft_draw_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->str[y])
	{
		x = 0;
		while (x < data->width / 50)
		{
			if (data->str[y][x] == '0')
				ft_color(data, x * 50, y * 50);
			x++;
		}
		y++;
	}
	ft_draw_player(data);
	// ft_draw_line(data);
	ft_draw_fov(data);
}

//----------------------------------------------------------------------------//

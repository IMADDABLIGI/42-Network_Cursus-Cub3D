/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:22:05 by idabligi          #+#    #+#             */
/*   Updated: 2023/06/19 10:28:37 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//----------------------------------------------------------------------------//

void	ft_abort(int id)
{
	if (id == 1)
		printf("\e[1;31mError in malloc!\n\e[0m");
	else if (id == 2)
		printf("\e[1;31mArgument please!\n\e[0m");
	exit(1);
}

//----------------------------------------------------------------------------//

int	ft_destroy(t_data *data)
{
	data = NULL;
	exit (0);
}

//----------------------------------------------------------------------------//

void	ft_end(int sig)
{
	(void)sig;
	exit (0);
}

//----------------------------------------------------------------------------//

int	ft_check_wall(t_data *data, int x, int y)
{
	if (x < 0 || x > data->width || y < 0 || y > data->height)
		return (2);
	int x1 = (x + 1) / 50;
	int x2 = (x - 1) / 50;
	int y1 = (y + 1) / 50;
	int y2 = (y - 1) / 50;
	
	x = x / 50;
	y = y / 50;
	if (y >= data->height / 50 || ft_strlen(data->str[y]) <= x)
		return 1;
    if (data->str[y] && data->str[y1] && data->str[y2])
    {
        if (data->str[y][x] == '1' || data->str[y][x1] == '1' || data->str[y][x2] == '1'
        || data->str[y1][x] == '1' || data->str[y2][x] == '1')
            return (1);
    }
	return (0);
}

//----------------------------------------------------------------------------//

void		ft_event(void *dat)
{
	t_data *data = dat;

	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		exit (0);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP) && (!ft_check_wall(data,
		(data->player.p_x + cos(data->player.rotation_angel) * 4), data->player.p_y + sin(data->player.rotation_angel) * 4)))// Up_Arrow 
	{
		data->player.p_x += 4 * cos(data->player.rotation_angel);
		data->player.p_y += 4 * sin(data->player.rotation_angel);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN) && (!ft_check_wall(data,
		(data->player.p_x - cos(data->player.rotation_angel) * 4), data->player.p_y - sin(data->player.rotation_angel) * 4)))// Down_Arrow 
	{
		data->player.p_x -= 4 * cos(data->player.rotation_angel);
		data->player.p_y -= 4 * sin(data->player.rotation_angel);
	}
	if	(mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		if (data->player.rotation_angel >= (2*M_PI))
			data->player.rotation_angel = 0;
		data->player.rotation_angel += M_PI / 180;

	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))// Left_Arrow 
	{
		if(data->player.rotation_angel < 0)
			data->player.rotation_angel += 2 * M_PI;
		data->player.rotation_angel -= (M_PI / 180);
	}
	mlx_delete_image(data->mlx, data->image);
	data->image = mlx_new_image(data->mlx, data->width,data->height);
	ft_draw_map(data);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
}

//----------------------------------------------------------------------------//
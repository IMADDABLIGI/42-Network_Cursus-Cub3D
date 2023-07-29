/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:42:36 by idabligi          #+#    #+#             */
/*   Updated: 2023/06/12 12:53:29 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main()
{
	t_data	data;

    signal(SIGINT, ft_end);
    ft_textures(&data);
	data.mlx = mlx_init(data.width, data.height, "cub3D", false);
    data.image = mlx_new_image(data.mlx, data.width, data.height);
    ft_draw_map(&data);
    mlx_loop_hook(data.mlx,ft_event, &data);
	mlx_loop(data.mlx);
}

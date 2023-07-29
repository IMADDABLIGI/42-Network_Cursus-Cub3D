/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:01:49 by idabligi          #+#    #+#             */
/*   Updated: 2023/06/16 11:25:56 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_textures(t_data *data)
{
	int	i;
	char *str[12] =
	{	"111111111111111",
		"100000000000101",
		"100001000000101",
		"111110000010101",
		"100000000010101",
		"100000001111101",
		"100000000000001",
		"100000000000001",
		"111111000111101",
		"100000000000001",
		"111111111111111"
	};

	i = 0;
	while (i < 11)
	{
		data->str[i] = ft_strdup(str[i]);
		i++;
	}
	data->str[11] = NULL;
	data->height = 11 * 50;
	data->width = 15 * 50;

	data->player.p_y = data->height / 2;
	data->player.p_x = data->width / 2;
	data->player.turn_drct = 0;
    data->player.rotation_angel = M_PI / 2;
    data->ray.fov = 60 * (M_PI / 180);
    data->ray.increment = data->ray.fov / data->width;
}

//----------------------------------------------------------------------------//

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:09:12 by idabligi          #+#    #+#             */
/*   Updated: 2023/06/17 13:47:32 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_find_distance(t_data *data, float x, float y)
{
	float	distance;

	distance = sqrt((x - data->player.p_x) * (x - data->player.p_x) + (y - data->player.p_y) * (y - data->player.p_y ));
	return (distance);
}

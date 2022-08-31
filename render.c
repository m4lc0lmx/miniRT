/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 14:59:49 by yed-dyb           #+#    #+#             */
/*   Updated: 2022/08/19 10:02:33 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// void render(t_camera camera, t_world world, t_world *img)
// {
//     int x;
//     int y = 0;
//     ray r;

//     while(y < HEIGHT) {
// 		x = 0;
// 		while(x < WIDTH) {
// 			r = ray_for_pixel(camera, x, y);
// 			colour color = color_at(world, r);
// 			// printf("%f, %f, %f\n", color.red, color.green, color.blue);
// 			my_mlx_pixel_put(img, x, y, create_trgb(1, color.red * 255 , color.green * 255 , color.blue * 255));
// 			x++;
// 		}
// 		y++;
// 	}
// }
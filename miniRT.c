/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:25:43 by yed-dyb           #+#    #+#             */
/*   Updated: 2022/08/27 16:10:05 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

typedef struct s_th {
	pthread_t th_id;
	int max;
	int min;
	t_world world;
	t_camera camera;
	t_data *img;
} t_th;

t_RGB initColour(double red, double green, double blue)
{
	t_RGB rgb;
	rgb.red = red;
	rgb.green = green;
	rgb.blue = blue;
	return (rgb);
}

void print_vector(t_vector v)
{
	printf("(x-> %f, y-> %f, z-> %f, w-> %f)\n\n", v.x, v.y, v.z, v.w);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void *render(void *arg)
{
	t_th *th;

	th = (t_th *)arg;

	ray r;
	int x, y = 0;

	while(y < HEIGHT)
	{
		x = th->min;
		while(x < th->max) {
			r = ray_for_pixel(th->camera, x, y);
			t_RGB color = color_at(th->world, r);
			my_mlx_pixel_put(th->img, x, y, create_trgb(1,
								min(color.red * 255, 255),
								min(color.green * 255, 255),
								min(color.blue * 255, 255)));
			x++;
		}
		y++;
	}

	return NULL;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	double 	t;

	t_data img;
	
	// t_world world;
	// t_light l;
	t_camera camera;

	t_world *world = parser(argc, argv);

	int i = 0;
	while(world->sphere[i])
	{
		sphereInit(world->sphere[i], *(world->ambient[0]));
		i++;
	}
	i = 0;
	while(world->plane[i])
	{
		planeInit(world->plane[i], *(world->ambient[0]));
		i++;
	}
	i = 0;
	while(world->cy[i])
	{
		cylinderInit(world->cy[i], *(world->ambient[0]));
		i++;
	}
	cameraInit(world->camera[0], WIDTH, HEIGHT);
	lightInit(world->light[0]);
	ambientInit(world->ambient[0]);

	// mlx
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "miniRT");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	t_th *th;
	int len = ceil(WIDTH / 100);

	th = malloc(len * sizeof(t_th));
	
	i = 0;
	while(i < len)
	{
		th[i].min = i * 100;
		th[i].max = i * 100 + 100;
		th[i].camera = *(world->camera[0]);
		th[i].world = *world;
		th[i].img = &img;

		pthread_create(&(th[i].th_id), NULL, render, &(th[i]));
		i++;
	}

	i = -1;
	while(++i < len)
		pthread_join(th[i].th_id, NULL);

	mlx_put_image_to_window(mlx, win, img.img, 0, 0);

	mlx_loop(mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 23:30:25 by yed-dyb           #+#    #+#             */
/*   Updated: 2022/07/26 10:56:47 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

vector position(ray r, float t)
{
    return (vectorAdd(r.start, vectorScale(r.dir, t)));
}

ray transform(ray r, matrix m, int type)
{
    ray new_ray;

    new_ray.start = vector_mult_matrix(r.start, m, type);
    new_ray.dir = vector_mult_matrix(r.dir, m, type);

    return (new_ray);
}

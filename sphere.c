/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:57:49 by yed-dyb           #+#    #+#             */
/*   Updated: 2022/08/04 15:20:34 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// sphere sphereInit(vector transform)
// {
//     sphere s;
//     s.pos = vectorInit(0, 0, 0, 1);
//     return s;
// }

// get the intersection of a ray with a sphere
double sphereIntersection(ray r, sphere s)
{
    double A;
    double B;
    double C;
    double t1;
    double t2;
    vector v;
    double tmp;
    double discriminant;
    ray r2;

    r2 = transform(r, s.transform, -1);
    // t = malloc(sizeof(double) * 2);

    v = vectorSub(r2.start, s.pos);
    A = vectorDot(r2.dir, r2.dir);
    B = 2 * vectorDot(r2.dir, v);
    C = vectorDot(v, v) - 1;
    discriminant =  B * B - 4 * A * C; 
    
    if (discriminant < 0)
        return (-1);
    else
    {
        t1 = (-B - sqrt(discriminant)) / (2 * A);
        t2 = (-B + sqrt(discriminant)) / (2 * A);

        if(t1 > t2)
                t1 = t2;

        if((t1 > 0.001f))
            return t1;
        else
            return (-1);
    }
}

// init sphere
sphere shpereInit()
{
    sphere s;

    s.pos = vectorInit(0, 0, 0, 1);
    s.transform = get_matrix(vectorInit(0, 0, 0, 1), 'i');
    s.material = materials();

    return s;
}

// get the normal vector in a sphere
vector normal_at_sphere(sphere s, vector p)
{
    vector obj_p = vector_mult_matrix(p, s.transform, -1);
    vector obj_n = vectorSub(obj_p, s.pos);
    vector world_n = vector_mult_matrix(obj_n, matrixTranspose(matrixInverse(s.transform)), 1);

    world_n.w = 0;

    return normalize(world_n);
}

// get the reflect vector of in vector
vector reflect(vector in, vector normal)
{
	return vectorSub(in, vectorScale(normal, 2 * vectorDot(in, normal)));
}
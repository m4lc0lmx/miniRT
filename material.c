/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:54:53 by yed-dyb           #+#    #+#             */
/*   Updated: 2022/08/03 11:56:15 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// materail init
material materials()
{
    material m;

    m.color = colourInit(0.8, 1.0, 0.6);
	m.ambient = 0.1;
    m.diffuse = 0.7;
    m.specular = 0.2;
    m.shininess = 100.0;

    return m;
}
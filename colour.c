/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:37:48 by yed-dyb           #+#    #+#             */
/*   Updated: 2022/07/27 11:42:14 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

colour colourInit(float r, float g, float b)
{
    colour c;

    c.red = r;
    c.green = g;
    c.blue = b;

    return c;
}
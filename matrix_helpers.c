/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:13:01 by yed-dyb           #+#    #+#             */
/*   Updated: 2022/07/02 20:06:41 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float determinant(matrix m)
{
    return (m.m[0][0] * m.m[1][1] - m.m[0][1] * m.m[1][0]);   
}

matrix submatrix(matrix m, int row, int col)
{
   int i;
   int j;
   int k;
   int n;
   matrix sub;

   sub = matrixCreate(m.rows - 1, m.cols - 1);
   i = -1;
   k = 0;
   while (++i < m.rows)
   {
        if (i != row)
        {
            j = -1;
            n = 0;
            while (++j < m.cols)
            {
                if (j != col)
                {
                    sub.m[k][n] = m.m[i][j];
                    n++;
                }
            }
            k++;
        }
   }
   return (sub);
}

float minor(matrix m, int row, int col)
{
    return (determinant(submatrix(m, row, col)));
}

float cofactor(float det, int row, int col)
{
    return (pow(-1, row + col) * det);
}

float matrixDeterminant(matrix m)
{
    int i;
    float det;

    if (m.rows == 2 && m.cols == 2)
        return (determinant(m));
    i = 0;
    det = 0;
    while(i < m.cols)
    {
        det += m.m[0][i] * cofactor(matrixDeterminant(submatrix(m, 0, i)), 0, i);
        i++;
    }
    return det;
}
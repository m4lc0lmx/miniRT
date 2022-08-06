/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:55:32 by yed-dyb           #+#    #+#             */
/*   Updated: 2022/08/02 16:20:57 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// print matrix
void print_matrix(matrix m)
{
   int j;
   int i = 0;
   while(i < m.rows)
   {
      j = 0;
      while(j < m.cols)
      {
         printf("%f|", m.m[i][j]);
         j++;
      }
      printf("\n");
      i++;
   }
   printf("\n");
}

// multiplu tow matrixes
matrix matrixMult(matrix m1, matrix m2)
{
   int i;
   int j;
   int k;
   matrix result;

   if (m1.cols != m2.rows)
      exit(1);
   result = matrixCreate(m1.rows, m2.cols);
   i = -1;
   while (++i < m1.rows)
   {
      j = -1;
      while (++j < m2.cols)
      {
         k = -1;
         while (++k < m1.cols)
            result.m[i][j] += m1.m[i][k] * m2.m[k][j];
      }
   }
   return (result);
}

// transpose matrix
matrix matrixTranspose(matrix m)
{
   int i;
   int j;
   matrix transpose;

   transpose = matrixCreate(m.rows, m.cols);

   i = -1;
   while (++i < m.rows)
   {
      j = -1;
      while (++j < m.cols)
         transpose.m[j][i] = m.m[i][j];
   }
   return (transpose);
}

// get the cofactor of the matrix
matrix cofactor_matrix(matrix m)
{
   int i, j;
   matrix matrix;

   matrix = matrixCreate(m.rows, m.cols);

   i = 0;
   while(i < m.rows)
   {
      j = 0;
      while(j < m.cols)
      {
         matrix.m[i][j] = cofactor(matrixDeterminant(submatrix(m, i, j)), i, j);
         j++;
      }
      i++;
   }

   return (matrix);
}

// devide a matrix by the determinant
matrix matrix_devide_by_det(matrix m, double det)
{
   int i;
   int j;
   matrix inverted;

   i = 0;
   inverted  = matrixCreate(m.rows, m.cols);
   while(i < m.rows)
   {
      j = 0;
      while(j < m.cols)
      {
         inverted.m[i][j] = m.m[i][j] / det;
         j++;
      }
      i++;
   }

   return(inverted);
}

// inverse the matrix
matrix matrixInverse(matrix m)
{
   double det;
   matrix matrix;

   det = matrixDeterminant(m);

   if (det == 0)
      exit(1);
   
   matrix = cofactor_matrix(m);
   matrix = matrixTranspose(matrix);
   matrix = matrix_devide_by_det(matrix, det);

   return (matrix);
}
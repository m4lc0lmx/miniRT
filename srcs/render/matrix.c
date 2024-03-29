/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:55:32 by yed-dyb           #+#    #+#             */
/*   Updated: 2022/09/04 20:16:28 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/miniRT.h"

// multiplu tow matrixes and free
t_matrix	matrix_mult(t_matrix m1, t_matrix m2)
{
	int			i;
	int			j;
	int			k;
	t_matrix	result;

	if (m1.cols != m2.rows)
		exit(1);
	result = matrix_create(m1.rows, m2.cols);
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
	free_matrix(m1);
	free_matrix(m2);
	return (result);
}

// transpose matrix
t_matrix	matrix_transpose(t_matrix m)
{
	int			i;
	int			j;
	t_matrix	transpose;

	transpose = matrix_create(m.rows, m.cols);
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
t_matrix	cofactor_matrix(t_matrix m)
{
	int			i;
	int			j;
	t_matrix	matrix;
	t_matrix	sub_matrix;

	matrix = matrix_create(m.rows, m.cols);
	i = 0;
	while (i < m.rows)
	{
		j = 0;
		while (j < m.cols)
		{
			sub_matrix = submatrix(m, i, j);
			matrix.m[i][j] = cofactor(
					matrix_determinant(sub_matrix), i, j);
			free_matrix(sub_matrix);
			j++;
		}
		i++;
	}
	return (matrix);
}

// devide a matrix by the determinant
t_matrix	matrix_devide_by_det(t_matrix m, double det)
{
	int			i;
	int			j;
	t_matrix	inverted;

	i = 0;
	inverted = matrix_create(m.rows, m.cols);
	while (i < m.rows)
	{
		j = 0;
		while (j < m.cols)
		{
			inverted.m[i][j] = m.m[i][j] / det;
			j++;
		}
		i++;
	}
	return (inverted);
}

// inverse the matrix
t_matrix	matrix_inverse(t_matrix m)
{
	double		det;
	t_matrix	matrix;
	t_matrix	tmp_matrix;

	det = matrix_determinant(m);
	if (det == 0)
	{
		error("ERROR: CAN'T TRANSFORM CAMERA");
		exit(1);
	}
	tmp_matrix = cofactor_matrix(m);
	matrix = matrix_transpose(tmp_matrix);
	free_matrix(tmp_matrix);
	tmp_matrix = matrix;
	matrix = matrix_devide_by_det(tmp_matrix, det);
	free_matrix(tmp_matrix);
	return (matrix);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:57:17 by ael-bach          #+#    #+#             */
/*   Updated: 2021/11/13 22:34:11 by ael-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;
	char	c1;

	p = (char *)s;
	c1 = (char)c;
	i = 0;
	while (p[i] != '\0' && p[i] != c1)
	{
		i++;
	}
	if (p[i] == c1)
	{
		return (p + i);
	}
	return (0);
}

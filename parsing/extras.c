/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparedes <aparedes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:43:55 by aparedes          #+#    #+#             */
/*   Updated: 2022/06/19 12:46:05 by aparedes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	checkborders(t_long *sl)
{
	int	x;
	int	y;

	x = (int)sl->x;
	y = (int)sl->y;
	x--;
	while (x)
	{
		if (sl->map[0][x] != '1' || sl->map[y - 1][x] != '1')
			showerror(sl, "Map is not surrounded/closed by walls");
		x--;
	}
	x = (int)sl->x;
	y--;
	while (y)
	{
		if (sl->map[y][x - 1] != '1' || sl->map[y][0] != '1')
			showerror(sl, "Map is not surrounded/closed by walls");
		y--;
	}
}

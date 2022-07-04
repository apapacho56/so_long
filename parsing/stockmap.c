/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stockmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparedes <aparedes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:07:13 by aparedes          #+#    #+#             */
/*   Updated: 2022/06/24 10:24:25 by aparedes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	stockmap(t_long *sl, char *filename)
{
	char	*line;
	int		fd;
	int		ret;
	int		nb;

	nb = 0;
	fd = open(filename, O_RDONLY);
	ret = get_next_line(fd, &line);
	while (line[numberblank(line)] == '1' || line[numberblank(line)] == '0')
	{
		stockline(sl, line, nb);
		if (ret != -1)
			free(line);
		ret = get_next_line(fd, &line);
		nb++;
	}
	free(line);
	return (0);
}

int	stockline(t_long *sl, char *line, int nb)
{
	int	index;

	index = 0;
	while (line[index])
	{
		sl->casetotal++;
		sl->map[nb][index] = replacechar(line[index]);
		if (line[index] == 'P')
		{
			sl->playerset++;
			sl->player_x = index;
			sl->player_y = nb;
		}
		if (line[index] == 'E')
			sl->exitset++;
		if (line[index] == 'C')
			sl->collectibletotal++;
		if (line[index] != 'P' && line[index] != 'E' && line[index]
			!= 'C' && line[index] != '1' && line[index] != '0')
			showerror(sl, "Wrong character in map");
		index++;
	}
	return (0);
}

int	checkmap(t_long *sl)
{
	if (sl->x > 25)
		showerror(sl, "The map is too big (excesive columns)");
	if (sl->y > 15)
		showerror(sl, "The map is too big (excesive rows)");
	if (sl->playerset < 1)
		showerror(sl, "You must set a player 'P'");
	if (sl->playerset > 1)
		showerror(sl, "Multiplayer mode unavailable");
	if (sl->exitset < 1)
		showerror(sl, "You must set an exit 'E'");
	if (sl->exitset > 10)
		showerror(sl, "You have too much exits");
	if (sl->collectibletotal == 0)
		showerror(sl, "You must set a collectible 'C'");
	checkthewall(sl);
	return (0);
}

int	mallocmap(t_long *sl)
{
	int	i;

	i = 0;
	sl->map = malloc(sizeof(char *) * sl->y);
	while (i < sl->y)
	{
		sl->map[i] = malloc(sizeof(char) * (sl->x + 1));
		i++;
	}
	sl->maptofree = 1;
	return (1);
}

int	checkifgood(char c)
{
	if (c != '0' && c != 'a' && c != '1' && c != 'P' && c != 'c' && c != 'E'
		&& c != 'd' && c != 'C' && c != 'e')
		return (0);
	return (1);
}

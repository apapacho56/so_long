/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparedes <aparedes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:54:37 by aparedes          #+#    #+#             */
/*   Updated: 2022/06/19 12:50:20 by aparedes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_hit(int keycode, t_long *sl)
{
	sl->keyboard[keycode] = 1;
	return (0);
}

int	ft_keyboard(t_long *sl)
{
	if (sl->keyboard[ADVANCE])
		moveplayer(1, sl);
	if (sl->keyboard[BACK])
		moveplayer(-1, sl);
	if (sl->keyboard[LEFT])
		moveplayer(2, sl);
	if (sl->keyboard[RIGHT])
		moveplayer(3, sl);
	if (sl->keyboard[ESC] == 1 || sl->keyboard[RED_BUTTON] == 1)
		freeandexit(sl);
	return (0);
}

int	closebyredbutton(t_long *sl)
{
	freeandexit(sl);
	sl->keyboard[79] = 1;
	return (0);
}

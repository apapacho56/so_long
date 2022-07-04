/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparedes <aparedes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:52:58 by aparedes          #+#    #+#             */
/*   Updated: 2022/06/21 09:53:08 by aparedes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	t_long	game;

	initvar(&game);
	if (argc == 1)
		showerror(&game, "Missing map (./so_long maps/intra.ber)");
	if (argc > 2)
		showerror(&game, "Too many arguments");
	parsing(&game, argv[1]);
	display(&game);
	return (0);
}

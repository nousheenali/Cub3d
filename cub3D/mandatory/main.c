/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:03:29 by sfathima          #+#    #+#             */
/*   Updated: 2022/12/14 09:30:11 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
	{
		printf("Wrong no. of arg!! Try ./cub3D map");
		return (1);
	}
	if (parse_map(&g, argv[1]))
		return (1);
	ft_init_variables(&g);
	if (ft_convert_xpm_to_img(&g))
		ft_close(&g);
	ft_start(&g);
	mlx_hook(g.win, 2, 1L << 0, &ft_button, &g);
	mlx_hook(g.win, 17, 0, ft_close, &g);
	mlx_loop(g.mlx);
}

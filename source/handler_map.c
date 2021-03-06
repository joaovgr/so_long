/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:50:59 by jvictor-          #+#    #+#             */
/*   Updated: 2022/01/27 21:58:51 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_move(int key_code, t_map *map)
{
	char	*count_mov;

	if (key_code == 'w' || key_code == 0xff52)
		move_up(map);
	else if (key_code == 's' || key_code == 0xff54)
		move_down(map);
	else if (key_code == 'd' || key_code == 0xff53)
		move_right(map);
	else if (key_code == 'a' || key_code == 0xff51)
		move_left(map);
	else if (key_code == 0xff1b)
		free_exit(map);
	print_images(map);
	count_mov = ft_itoa(map->count_mov);
	ft_putendl_fd(count_mov, 1);
	mlx_string_put(map->mlx_ptr, map->win_ptr,
		10, 20, 0xFFFFFF, count_mov);
	free(count_mov);
	return (0);
}

void	handler_map(t_map *map)
{
	mlx_expose_hook(map->win_ptr, print_images, map);
	print_images(map);
	mlx_hook(map->win_ptr, 2, 1L << 0, player_move, map);
	mlx_hook(map->win_ptr, 33, 1L << 5, free_mallocs, map);
	mlx_loop(map->mlx_ptr);
}

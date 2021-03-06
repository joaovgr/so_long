/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mallocs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 01:13:38 by jvictor-          #+#    #+#             */
/*   Updated: 2022/01/27 21:11:16 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_mallocs(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i] != NULL)
	{
		free(map->map[i]);
		i++;
	}
	if (map->mlx_ptr != 0)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		mlx_destroy_display(map->mlx_ptr);
		free(map->mlx_ptr);
	}
	exit (0);
	return (0);
}

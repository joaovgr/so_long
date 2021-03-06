/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:51:01 by jvictor-          #+#    #+#             */
/*   Updated: 2022/01/26 23:44:31 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *map)
{
	if (map->map[map->player_line - 1][map->player_col] == 'C')
	{
		walk(map, 'u', map->player_line, map->player_col);
		map->count_c--;
	}
	else if (map->map[map->player_line - 1][map->player_col] == 'E')
	{
		if (map->count_c == 0)
			free_exit(map);
	}
	else if (map->map[map->player_line - 1][map->player_col] == '0')
	{
		walk(map, 'u', map->player_line, map->player_col);
	}
	if (map->mov_up == 1)
		map->mov_up = 0;
	else
		map->mov_up = 1;
	map->last_movement = 1;
}

void	move_down(t_map *map)
{
	if (map->map[map->player_line + 1][map->player_col] == 'C')
	{
		walk(map, 'd', map->player_line, map->player_col);
		map->count_c--;
	}
	else if (map->map[map->player_line + 1][map->player_col] == 'E')
	{
		if (map->count_c == 0)
			free_exit(map);
	}
	else if (map->map[map->player_line + 1][map->player_col] == '0')
	{
		walk(map, 'd', map->player_line, map->player_col);
	}
	if (map->mov_down == 1)
		map->mov_down = 0;
	else
		map->mov_down = 1;
	map->last_movement = 2;
}

void	move_right(t_map *map)
{
	if (map->map[map->player_line][map->player_col + 1] == 'C')
	{
		walk(map, 'r', map->player_line, map->player_col);
		map->count_c--;
	}
	else if (map->map[map->player_line][map->player_col + 1] == 'E')
	{
		if (map->count_c == 0)
			free_exit(map);
	}
	else if (map->map[map->player_line][map->player_col + 1] == '0')
	{
		walk(map, 'r', map->player_line, map->player_col);
	}
	if (map->mov_right == 1)
		map->mov_right = 0;
	else
		map->mov_right = 1;
	map->last_movement = 3;
}

void	move_left(t_map *map)
{
	if (map->map[map->player_line][map->player_col - 1] == 'C')
	{
		walk(map, 'l', map->player_line, map->player_col);
		map->count_c--;
	}
	else if (map->map[map->player_line][map->player_col - 1] == 'E')
	{
		if (map->count_c == 0)
			free_exit(map);
	}
	else if (map->map[map->player_line][map->player_col - 1] == '0')
	{
		walk(map, 'l', map->player_line, map->player_col);
	}
	if (map->mov_left == 1)
		map->mov_left = 0;
	else
		map->mov_left = 1;
	map->last_movement = 4;
}

void	walk(t_map *map, char direction, int line, int col)
{
	if (direction == 'u')
	{
		map->map[line - 1][col] = 'P';
		map->map[line][col] = '0';
		map->player_line -= 1;
	}
	else if (direction == 'd')
	{
		map->map[line + 1][col] = 'P';
		map->map[line][col] = '0';
		map->player_line += 1;
	}
	else if (direction == 'r')
	{
		map->map[line][col + 1] = 'P';
		map->map[line][col] = '0';
		map->player_col += 1;
	}
	else if (direction == 'l')
	{
		map->map[line][col - 1] = 'P';
		map->map[line][col] = '0';
		map->player_col -= 1;
	}
	map->count_mov++;
}

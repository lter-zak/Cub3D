/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:00:48 by lter-zak          #+#    #+#             */
/*   Updated: 2023/04/13 21:47:50 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_front_back_x(char **gen_map, int i, int y, int flag)
{
	while (gen_map[i][y])
	{
		if (gen_map[i][y] == '1')
			return (1);
		if (flag == 1)
			y++;
		if (flag == 2)
			y--;
	}
	return (0);
}

int	check_x(char **gen_map, int i, int y)
{
	int	flag_f;
	int	flag_b;

	flag_f = 0;
	flag_b = 0;
	flag_f = check_front_back_x(gen_map, i, y, 1);
	flag_b = check_front_back_x(gen_map, i, y, 2);
	if (flag_f == 0 || flag_b == 0)
		return (1);
	return (0);
}

int	check_up_down_y(char **gen_map, int i, int y, int flag)
{
	while (gen_map[i][y])
	{
		if (gen_map[i][y] == '1')
			return (1);
		if (flag == 1)
			i--;
		if (flag == 2)
			i++;
	}
	return (0);
}

int	check_y(char **gen_map, int i, int y)
{
	int	flag_u;
	int	flag_d;

	flag_u = 0;
	flag_d = 0;
	flag_u = check_up_down_y(gen_map, i, y, 1);
	flag_d = check_up_down_y(gen_map, i, y, 2);
	if (flag_u == 0 || flag_d == 0)
	{
		printf("sssss = \n");
		return (1);
	}
	return (0);
}

int	check_zero(char **gen_map)
{
	int	j;
	int i;

	i = 0;
	j = 0;
	while (gen_map[i][j])
	{
		j = 0;
		while (gen_map[i][j])
		{
			if (gen_map[i][j] == '0')
			{
				if (check_x(gen_map, i, j) || check_y(gen_map, i, j))
				{
					printf("smt is wrong in map");
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

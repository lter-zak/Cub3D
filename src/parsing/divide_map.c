/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:51:24 by lter-zak          #+#    #+#             */
/*   Updated: 2023/04/06 14:31:41 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_color(char **gen_map, int i, int j, t_info **info)
{
	int	tmp_start;
	int	tmp_end;

	tmp_start = 0;
	tmp_end = 0;
	(void)info;
	j++;
	while (gen_map[i][j] && gen_map[i][j] == ' ')
		j++;
	tmp_start = j;
	while (gen_map[i][j] != ' ' && gen_map[i][j])
		j++;
	tmp_end = j;
	if (gen_map[i][j])
	{
		while (gen_map[i][j] && gen_map[i][j] == ' ')
			j++;
		if (gen_map[i][j] && gen_map[i][j] != '\n')
			printf("ERR\n");
	}
	printf("str = %s\n" ,ft_substr(gen_map[i], tmp_start, tmp_end - tmp_start));
	return (0);
}

int	ft_colors(char **gen_map, int i, int j, t_info **info)
{
	(void)info;
	if (gen_map[i][j] == 'F' || gen_map[i][j] == 'C')
	{
		if (!gen_map[i][j + 1] || (gen_map[i][j + 1]
		&& gen_map[i][j + 1] != ' '))
		{
			printf("errr\n");
			return (0);
		}
		if (parse_color(gen_map, i, j, info))
			return (0);
	}
	return (1);
}

void	divide_clr_txtr(char **gen_map, t_info **info)
{
	int	count;
	int	i;
	int	j;

	(void)info;
	count = 0;
	i = 0;
	j = 0;
	while (gen_map[i])
	{
		j = 0;
		while (gen_map[i][j] == ' ')
			j++;
		count += ft_colors(gen_map, i, j, info);
		// count += ft_texture(gen_map, i, j, info);
		// printf("gen_map = %s\n", gen_map[i]);
		i++;
	}
}

void	divide_gen_map(char **gen_map, t_info **info)
{
	(void)info;
	divide_clr_txtr(gen_map, info);
	//divide_map();
}

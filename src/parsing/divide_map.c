/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:51:24 by lter-zak          #+#    #+#             */
/*   Updated: 2023/04/07 13:49:11 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_to_info(char **color_map, t_info **info, char c)
{
	int j;
	(void)info;
	j = 0;
	if (c == 'F')
	{
		if ((*info)->flag_c_f)
		{
			free(color_map);		
			return (1);
		}
		while (color_map[j])
		{
			(*info)->colors_f[j] = color_map[j];
			j++;
		}
		(*info)->flag_c_f = 1;
	}
	else if (c == 'C')
	{
		if ((*info)->flag_c_c)
		{
			matrix_free(color_map);
			return (1);
		}
		while (color_map[j])
		{
			(*info)->colors_c[j] = color_map[j];
			j++;
		}
		(*info)->flag_c_c = 1;
	}
	free(color_map);
	return (0);
}

int	check_color_argument(char **color_map)
{
	int	i;

	i = 0;
	while (color_map[i])
	{
		if (ft_atoi(color_map[i]) >= 0 && ft_atoi(color_map[i]) <= 255)
			i++;
		else
			return (1);
	}
	return (0);
}

int	split_color_argument(char *str, t_info **info, char c)
{
	char	**color_map;
	int		len;
	(void)c;
	(void)info;
	len = 0;
	color_map = ft_split(str, ',');
	free(str);
	len = matrix_len(color_map);
	if (len != 3 || check_color_argument(color_map))
	{
		matrix_free(color_map);
		return (1);
	}
	if (color_to_info(color_map, info, c))
		return (1);
	return (0);
}

int	parse_color_argument(char *str, t_info **info, char c)
{
	int		i;

	(void)info;
	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ',' || str[i] == '\n')
			i++;
		else
		{
			free(str);
			return (1);
		}
	}
	if (split_color_argument(str, info, c))
		return (1);
	return (0);
}

int	parse_color(char **gen_map, int i, int j, t_info **info)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	char c;
	
	(void)info;
	c = gen_map[i][j];
	j++;
	while (gen_map[i][j] && gen_map[i][j] == ' ')
		j++;
	start = j;
	while (gen_map[i][j] != ' ' && gen_map[i][j])
		j++;
	end = j;
	if (gen_map[i][j])
	{
		while (gen_map[i][j] && gen_map[i][j] == ' ')
			j++;
		if (gen_map[i][j] && gen_map[i][j] != '\n')
			return (1);
	}
	if (parse_color_argument(ft_substr(gen_map[i], start, end - start), info, c))
		return (1);
	//printf("str = %s\n" ,ft_substr(gen_map[i], start, end - start));
	return (0);
}

int	ft_colors(char **gen_map, int i, t_info **info, int *count)
{
	int	j;

	(void)info;
	j = 0;
	while (gen_map[i][j] == ' ')
			j++;
	if (gen_map[i][j] == 'F' || gen_map[i][j] == 'C')
	{
		if (!gen_map[i][j + 1] || (gen_map[i][j + 1]
		&& gen_map[i][j + 1] != ' '))
		{
			printf("Colors identifier must be 'F' or 'C'\n");
			return (1);
		}
		if (parse_color(gen_map, i, j, info))
		{
			printf("Invalid argument for color\n");
			return (1);
		}
	(*count)++;
	}
	return (0);
}

int	divide_clr_txtr(char **gen_map, t_info **info)
{
	int	count;
	int	i;

	(void)info;
	count = 0;
	i = 0;
	while (gen_map[i])
	{
		if (ft_colors(gen_map, i, info, &count))
			return (1);
		//printf("count = %d\n", count);
	//ft_texture(gen_map, i, j, info);
		// printf("gen_map = %s\n", gen_map[i]);
		i++;
	}
	return (0);
}

int	divide_gen_map(char **gen_map, t_info **info)
{
	(void)info;
	if (divide_clr_txtr(gen_map, info))
		return (1);
	//divide_map();
	return (0);
}

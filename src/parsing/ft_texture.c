/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:00:44 by lter-zak          #+#    #+#             */
/*   Updated: 2023/04/11 16:07:23 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	texture_to_info(char *str, t_info **info, int flag)
{
	if (flag == 1)
	{
		if ((*info)->flag_tex_no)
			return (1);
	(*info)->flag_tex_no = 1;
	(*info)->texture_no = str;
	}
	if (flag == 2)
	{
		if ((*info)->flag_tex_so)
			return (1);
	(*info)->flag_tex_so = 1;
	(*info)->texture_so = str;
	}
	if (flag == 3)
	{
		if ((*info)->flag_tex_we)
			return (1);
	(*info)->flag_tex_we = 1;
	(*info)->texture_we = str;
	}
	if (flag == 4)
	{
		if ((*info)->flag_tex_ea)
			return (1);
	(*info)->flag_tex_ea = 1;
	(*info)->texture_ea = str;
	}
	return (0);
}

int	texture_check(char **g_map, int i, t_info **info, int flag)
{
	char	*str;
	int		start;
	int		fd;
	int		j;

	j = 0;
	while (g_map[i][j] == ' ' || g_map[i][j] == '\t' )
			j++;
	j += 2;
	while (g_map[i][j] == ' ' || g_map[i][j] == '\t')
			j++;
	start = j;
	while (g_map[i][j] != ' ' && g_map[i][j] != '\n'&& g_map[i][j] != '\t')
			j++;
	str = ft_substr(g_map[i], start, j - start);
		fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		printf("Invalid Texture\n");
		free(str);
		return (1);
	}
	if (texture_to_info(str, info, flag))
		return (1);
	return (0);
}

int	texture_check_to_info(char **gen_map, int i, int j, t_info **info)
{
	(void)info;
	if (gen_map[i][j] == 'N' && gen_map[i][j + 1] == 'O')
	{
		if (texture_check(gen_map, i, info, 1))
			return (1);
	}
	if (gen_map[i][j] == 'S' && gen_map[i][j + 1] == 'O')
	{
		if (texture_check(gen_map, i, info, 2))
			return (1);
	}
	if (gen_map[i][j] == 'W' && gen_map[i][j + 1] == 'E')
	{
		if (texture_check(gen_map, i, info, 3))
			return (1);
	}
	if (gen_map[i][j] == 'E' && gen_map[i][j + 1] == 'A')
	{
		if (texture_check(gen_map, i, info, 4))
			return (1);
	}
	return (0);
}

int	ft_texture(char **gen_map, int i, t_info **info)
{
	int	j;

	(void)info;
	j = 0;
	while (gen_map[i][j] == ' ' || gen_map[i][j] == '\t')
			j++;
	if ((gen_map[i][j] == 'N' && gen_map[i][j + 1] == 'O')
		|| (gen_map[i][j] == 'S' && gen_map[i][j + 1] == 'O')
		|| (gen_map[i][j] == 'W' && gen_map[i][j + 1] == 'E')
		|| (gen_map[i][j] == 'E' && gen_map[i][j + 1] == 'A'))
	{
		if (!gen_map[i][j + 2] || (gen_map[i][j + 2]
		&& gen_map[i][j + 2] != ' ' && gen_map[i][j + 2] != '\t'))
		{
			printf("Error in texture\n");
			return (1);
		}
		else if (texture_check_to_info(gen_map, i, j, info))
			return (1);
	}
	return (0);
}
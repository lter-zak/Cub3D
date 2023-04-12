/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:51:24 by lter-zak          #+#    #+#             */
/*   Updated: 2023/04/11 19:19:52 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	divide_map(char **gen_map, t_info **info)
// {
// 	int	i;

// 	i = 0;
// 	whiel(gen_map[i][0])
	
// }

int	divide_clr_txtr(char **gen_map, t_info **info)
{
	int	count;
	int	i;

	(void)info;
	count = 0;
	i = 0;
	while (i < 6)
	{
		if (ft_colors(gen_map, i, info, &count))
			return (1);
		if (ft_texture(gen_map, i, info))
			return (1);
		i++;
	}
	if ((*info)->flag_c_f && (*info)->flag_c_c && (*info)->flag_tex_no
		&& (*info)->flag_tex_so && (*info)->flag_tex_we && (*info)->flag_tex_ea)
		return (0);
	else
	{
		printf("Txt and color error\n");
		return (1);
	}
}

int	divide_gen_map(char **gen_map, t_info **info)
{
	(void)info;
	if (divide_clr_txtr(gen_map, info))
		return (1);
	// if (divide_map(gen_map, info))
	// 	return (1);
	return (0);
}

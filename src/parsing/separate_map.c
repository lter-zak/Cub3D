/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:28:50 by lter-zak          #+#    #+#             */
/*   Updated: 2023/04/13 21:03:19 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_longest_str(char **gen_map, int i, int index)
{
	int	len;
	int	tmp_len;

	len = 0;
	tmp_len = 0;
	while (i <= index)
	{
		tmp_len = ft_strlen(gen_map[i]);
		if (tmp_len > len)
			len = tmp_len;
	i++;
	}
	printf("len = %d\n", len);
	return (len);
}

void	separate_map(t_info **info, char **gen_map, int index, int i)
{
	int	long_str;
	(void)info;
	long_str = find_longest_str(gen_map, i, index);
}

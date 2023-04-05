/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:21:09 by lter-zak          #+#    #+#             */
/*   Updated: 2023/04/05 12:59:29 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char **map_to_matrix( int fd)
{
	int		i;
	char	*str;
	char	**map;

	i = 0;
	// copy = map;
		//map = NULL;
		map = malloc(sizeof(char *) * 25);
	str = get_next_line(fd);
	while (str)
	{
		map[i] = str;
		str = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	// map = copy;
	//  printf("%s", map[7]);
	return (map);
}

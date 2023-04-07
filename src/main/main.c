/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:57:59 by lter-zak          #+#    #+#             */
/*   Updated: 2023/04/07 13:50:25 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	info->colors_c =malloc(sizeof(char *) * 4);
	info->colors_f =malloc(sizeof(char *) * 4);
	if (parsing(argc, argv, &info))
	{
		sleep(1000);
		return (1);
	}
	printf("info = %s\n", info->colors_c[0]);
	sleep(1000);
	return (0);
}

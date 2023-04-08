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
	info->flag_c_f = 0;
	info->flag_c_c = 0;
		printf("clor = %d\n", info->flag_c_f);
	if (parsing(argc, argv, &info))
	{
		sleep(1000);
		return (1);
	}
	int i = 0;
	while (info->colors_c &&info->colors_c[i])
	{
		printf("clor = %s\n", info->colors_c[i]);
		i++;
	}
	i = 0;
	while (info->colors_f && info->colors_f[i])
	{
		printf("colors = %s\n", info->colors_f[i]);
		i++;
	}
	// printf("info = %s\n", info->colors_c[1]);
	 //matrix_free(info->colors_c);
	// matrix_free(info->colors_f);
	// free(info);
	sleep(1000);
	return (0);
}

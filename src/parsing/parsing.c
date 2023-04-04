/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:58:10 by lter-zak          #+#    #+#             */
/*   Updated: 2023/04/04 12:45:02 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_exist(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		printf("Map does not exist\n");
		exit(0);
	}
	return (fd);
}

void	check_extension(char *argv)
{
	int	i;
	int	len;

	len = ft_strlen(argv);
	i = len - 1;
	while (argv[i])
	{
		if (argv[i] == 'b' && argv[i - 1]
			&& argv[i - 1] == 'u' && argv[i - 2]
			&& argv[i - 2] == 'c' && argv[i - 3]
			&& argv[i - 3] == '.')
			return ;
		else
		{
			printf("Invalid extension\n");
			exit(0);
		}
	}
}

void	check_argc(int argc)
{
	if (argc == 1)
	{
		printf("Not enough arguments\n");
		exit(0);
	}
	else if (argc > 2)
	{
		printf("Too many arguments\n");
		exit(0);
	}
}

void	parsing(int argc, char **argv)
{
	int	fd;

	fd = 0;
	check_argc(argc);
	check_extension(argv[1]);
	fd = check_map_exist(argv[1]);
	printf("fd = %d\n", fd);
}

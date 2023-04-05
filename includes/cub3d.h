/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:03:08 by lter-zak          #+#    #+#             */
/*   Updated: 2023/04/05 12:54:51 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE  1

typedef struct s_map
{
	char	**map;
	int		len;
}			t_map;

//parsing
void	parsing(int argc, char **argv);
char	**map_to_matrix(int fd);
//libft
int		ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
int		ft_strlcpy(char *dst, char *src, int destsize);
#endif
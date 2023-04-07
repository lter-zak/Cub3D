/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:03:08 by lter-zak          #+#    #+#             */
/*   Updated: 2023/04/07 13:46:07 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE  1

typedef struct s_info
{
	char	**map;
	char	**colors_f;
	char	**colors_c;
	char	**texture;
}			t_info;

//parsing
int		parsing(int argc, char **argv, t_info **info);
char	**map_to_matrix(int fd, int len);
int		divide_gen_map(char **gen_map, t_info **info);
//libft
char	*ft_strdup(char *s1);
int		ft_strlen(char *str);
int		matrix_len(char **str);
void	matrix_free(char **str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
char	*ft_substr(char *s, int start, int len);
int		ft_strlcpy(char *dst, char *src, int destsize);
char	**ft_split(char const *s, char c);
long long	ft_atoi(const char *str);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 10:03:52 by exam              #+#    #+#             */
/*   Updated: 2015/03/25 10:39:27 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNT_ISLAND_H
# define COUNT_ISLAND_H

typedef struct	s_env
{
	char			*map;
	int				map_size;
	int				map_width;
}				t_env;

# define BUFF_SIZE		512

# define MAX_LINE_LEN	1024

# define CHAR_ISLAND	'X'
# define CHAR_SEA		'.'

int				island_read(t_env *env, const char *file);
int				island_check(t_env *env);
void			island_count(t_env *env);

#endif

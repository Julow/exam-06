/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   island_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 10:25:57 by exam              #+#    #+#             */
/*   Updated: 2015/03/25 10:49:56 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_island.h"

static void		track_island(t_env *env, int i, char count)
{
	env->map[i] = count;
	if (i > env->map_width && env->map[i - env->map_width] == CHAR_ISLAND)
		track_island(env, i - env->map_width, count);
	if ((i + env->map_width) < env->map_size
			&& env->map[i + env->map_width] == CHAR_ISLAND)
		track_island(env, i + env->map_width, count);
	if (i > 0 && env->map[i - 1] == CHAR_ISLAND)
		track_island(env, i - 1, count);
	if ((i + 1) < env->map_size && env->map[i + 1] == CHAR_ISLAND)
		track_island(env, i + 1, count);
}

void			island_count(t_env *env)
{
	int				i;
	char			count;

	env->map_width++;
	i = -1;
	count = '0';
	while (++i < env->map_size)
		if (env->map[i] == CHAR_ISLAND)
			track_island(env, i, count++);
}

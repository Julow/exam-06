/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   island_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 10:18:58 by exam              #+#    #+#             */
/*   Updated: 2015/03/25 10:47:36 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_island.h"

int				island_check(t_env *env)
{
	int				line_len;
	int				i;

	line_len = 0;
	while (env->map[line_len] != '\n' && line_len < env->map_size)
		line_len++;
	if (line_len > MAX_LINE_LEN || line_len == 0)
		return (0);
	env->map_width = line_len;
	i = 0;
	line_len = 0;
	while (i < env->map_size)
	{
		if (env->map[i] == '\n')
		{
			if ((i - line_len) != env->map_width)
				return (0);
			line_len = i + 1;
		}
		else if (env->map[i] != CHAR_ISLAND && env->map[i] != CHAR_SEA)
			return (0);
		i++;
	}
	return (1);
}

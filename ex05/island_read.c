/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   island_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 10:09:30 by exam              #+#    #+#             */
/*   Updated: 2015/03/25 10:45:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_island.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static void		str_cpy(char *dst, const char *src, int len)
{
	int				i;

	i = -1;
	while (++i < len)
		dst[i] = src[i];
	dst[i] = '\0';
}

static int		island_concat(t_env *env, const char *buff, int len)
{
	char			*tmp;

	if ((tmp = (char*)malloc(len + env->map_size + 1)) == NULL)
		return (0);
	if (env->map != NULL)
		str_cpy(tmp, env->map, env->map_size);
	str_cpy(tmp + env->map_size, buff, len);
	if (env->map != NULL)
		free(env->map);
	env->map = tmp;
	env->map_size += len;
	return (1);
}

int				island_read(t_env *env, const char *file)
{
	int				fd;
	int				len;
	char			buff[BUFF_SIZE];

	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	env->map_size = 0;
	env->map = NULL;
	while ((len = read(fd, buff, BUFF_SIZE)) > 0)
		if (!island_concat(env, buff, len))
			return (0);
	close(fd);
	if (len < 0 || env->map == NULL)
		return (0);
	return (1);
}

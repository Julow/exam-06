/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 10:04:21 by exam              #+#    #+#             */
/*   Updated: 2015/03/25 10:41:57 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_island.h"
#include <unistd.h>

int				main(int argc, char **argv)
{
	t_env			env;

	if (argc <= 1 || !island_read(&env, argv[1]))
		return (write(1, "\n", 1), 1);
	if (!island_check(&env))
		return (write(1, "\n", 1), 1);
	island_count(&env);
	write(1, env.map, env.map_size);
	if (env.map[env.map_size - 1] != '\n')
		write(1, "\n", 1);
	return (0);
}

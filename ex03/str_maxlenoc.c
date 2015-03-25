/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 09:36:53 by exam              #+#    #+#             */
/*   Updated: 2015/03/25 09:52:55 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct	s_sub
{
	char			*str;
	int				len;
}				t_sub;

#define SUB(s,l)	((t_sub){(s), (l)})

int				ft_strstr(const char *s1, const t_sub *sub)
{
	int				i;
	int				j;

	i = -1;
	while (s1[++i] != '\0')
	{
		j = 0;
		while (j < sub->len && sub->str[j] == s1[j + i])
			j++;
		if (j >= sub->len)
			return (1);
	}
	return (0);
}

int				ft_strstrs(char **args, t_sub sub)
{
	while (*args != NULL)
	{
		if (!ft_strstr(*args, &sub))
			return (0);
		args++;
	}
	return (1);
}

int				main(int argc, char **argv)
{
	t_sub			max;
	t_sub			sub;

	if (argc > 1)
	{
		sub = SUB(argv[1], 0);
		max = sub;
		while (1)
		{
			if (sub.str[sub.len] == '\0')
				break ;
			if (ft_strstrs(argv + 2, SUB(sub.str, sub.len + 1)))
				sub.len++;
			else
				sub.str++;
			if (sub.len > max.len)
				max = sub;
		}
		write(1, max.str, max.len);
	}
	write(1, "\n", 1);
	return (0);
}

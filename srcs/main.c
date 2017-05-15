/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:00:46 by ulefebvr          #+#    #+#             */
/*   Updated: 2017/05/14 18:02:43 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "option.h"
#include "ft_ping.h"

#include <stdio.h>
#include <stdlib.h>

void				usage(void)
{
	dprintf(2, "%s\n", "./ft_ping [vh] destination");
}

int					get_option(int ac, char **av, int *opt)
{
	int				ch;
	t_arguments		args;

	ch = 0;
	args = (t_arguments){ac, av, NULL};
	while ((ch = option_getopt(&args, OPTIONS)) != -1)
	{
		if (ch == '?')
		{
			usage();
			return (-1);
		}
		*opt |= 1 << (ft_strchr(OPTIONS, ch) - OPTIONS);
	}
	return (0);
}

int					main(int ac, char **av)
{
	int				opt;

	opt = 0;
	if (getuid() != 0)
	{
		dprintf(2, "%s\n", "Need root privilege to execute.");
		return (EXIT_FAILURE);
	}
	if (ac < 2
		|| (get_option(ac, av, &opt) == -1
		|| (ac - g_option_optind) != 1))
	{
		usage();
		return (EXIT_FAILURE);
	}
	return (ft_ping(opt, *(av + g_option_optind)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:00:46 by ulefebvr          #+#    #+#             */
/*   Updated: 2017/05/20 17:27:06 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "option.h"
#include "ft_ping.h"

#include <stdio.h>
#include <stdlib.h>

void		usage(void)
{
	dprintf(2, "%s\n", "./ft_ping [vh] destination");
}

int			get_option(int ac, char **av, int *opt)
{
	int				ch;
	t_arguments		args;

	ch = 0;
	args = (t_arguments){ac, av, NULL};
	while ((ch = option_getopt(&args, OPTIONS)) != -1)
	{
		if (ch == '?')
			return (-1);
		*opt |= 1 << (ft_strchr(OPTIONS, ch) - OPTIONS);
	}
	return (0);
}

void		initiate_env(void)
{
	ft_bzero(&env, sizeof(t_env));
	env.datalen = DEFDATALEN;
	env.ident = getpid();
}

int			main(int ac, char **av)
{
	if (getuid() != 0)
	{
		dprintf(2, "%s\n", "Need root privilege to execute.");
		return (EXIT_FAILURE);
	}
	initiate_env();
	if (ac < 2
		|| (get_option(ac, av, &env.options) == -1
		|| (ac - g_option_optind) != 1))
	{
		usage();
		return (EXIT_FAILURE);
	}
	handle_signal();
	env.destination = *(av + g_option_optind);
	return (ft_ping());
}

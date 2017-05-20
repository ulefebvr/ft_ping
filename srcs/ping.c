/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:49:00 by ulefebvr          #+#    #+#             */
/*   Updated: 2017/05/16 18:28:59 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_ping(void)
{
	int				status;
	t_addrinfo		*tmp;

	tmp = NULL;
	env.socket = createsocket();
	ping_getaddrinfo(env.destination, &(env.hints), &(env.res));
	tmp = env.res;
	while (tmp)
	{
		if (tmp->ai_family == AF_INET)
			status = ping4(tmp);
		else if (tmp->ai_family == AF_INET6)
			break;
		else
		{
			dprintf(2, "ft_ping: "
				"unknown protocol family: %d\n", tmp->ai_family);
			exit(2);
		}
		if (status == 0)
			break;
		tmp = tmp->ai_next;
	}
	return (0);
}

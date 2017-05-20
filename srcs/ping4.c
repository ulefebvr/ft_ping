/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 18:15:47 by ulefebvr          #+#    #+#             */
/*   Updated: 2017/05/20 20:50:10 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

#include <stdio.h>

void	display_ping4(t_addrinfo *ai)
{
	char	ip_share[ADDRSTRLEN];

	inet_ntop(env.res->ai_family, 
		&(((struct sockaddr_in *)ai->ai_addr)->sin_addr), ip_share, ADDRSTRLEN);
	printf("PING %s (%s) ", env.destination, ip_share);
	printf("%d(%d) bytes of data.\n",
		env.datalen, env.datalen + 8 + env.optlen + 20);
}

int		ping4(t_addrinfo *ai)
{
	int				packlen;
	unsigned char	*pack;

	display_ping4(ai);
	ping_setup_socket(env.socket);
	packlen = env.datalen + MAXIPLEN + MAXICMPLEN;
	if (!(pack = (unsigned char *)malloc(packlen * sizeof(unsigned char))))
	{
		dprintf(2, "Error: %s\n", "ft_ping out of memory");
		exit(2);
	}
	ping_looping(&(t_funset){}, env.socket, pack, packlen);
	return (0);
}

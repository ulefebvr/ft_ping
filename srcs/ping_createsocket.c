/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping_createsocket.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:47:35 by ulefebvr          #+#    #+#             */
/*   Updated: 2017/05/16 17:59:36 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>

/*
** int socket(int domain, int type, int protocol)
** 
** domain:
** Name                Purpose                          Man page
** AF_INET             IPv4 Internet protocols          ip(7)
** AF_INET6            IPv6 Internet protocols          ipv6(7)
** 
** type:
** SOCK_DGRAM      Supports datagrams (connectionless, unreliable messages of a
**                 fixed maximum length).
** 
** protocol:
** IPPROTO_ICMP            # control message protocol
** IPPROTO_ICMPV6          # ICMP6
*/

int		createsocket(void)
{
	int			s;

	if ((s = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) == -1)
	{
		dprintf(2, "Error: %s\n", "Error creating socket.");
		exit(2);
	}
	return (s);
}

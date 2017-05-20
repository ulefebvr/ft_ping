/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping_getaddrinfo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 17:42:30 by ulefebvr          #+#    #+#             */
/*   Updated: 2017/05/16 18:25:51 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"
#include "libft.h"

#include <stdio.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int		ping_getaddrinfo(char *dest, t_addrinfo *hints, t_addrinfo **res)
{
	hints->ai_family = AF_INET;
	if (getaddrinfo(dest, NULL, hints, res) != 0)
	{
		dprintf(2, "Error: %s\n", "Getaddrinfo fail.");
		exit(2);
	}
	return (0);
}

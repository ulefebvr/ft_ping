/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping_getip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 17:18:48 by ulefebvr          #+#    #+#             */
/*   Updated: 2017/05/14 18:21:31 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"
#include "libft.h"

#include <stdio.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

char		*ping_getipfromadress(char *destination)
{
	struct addrinfo		hints;
	struct addrinfo		*res;
	struct sockaddr_in	*sa_in;
	char				ip_share[ADDRSTRLEN];

	ft_bzero(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	if (getaddrinfo(destination, NULL, &hints, &res) < 0)
	{
		dprintf(2, "Error: %s\n", "Getaddrinfo fail.");
		return (NULL);
	}
	sa_in = (struct sockaddr_in *)res->ai_addr;
	inet_ntop(res->ai_family, &(sa_in->sin_addr), ip_share, ADDRSTRLEN);
	return (ft_strdup(ip_share));
}

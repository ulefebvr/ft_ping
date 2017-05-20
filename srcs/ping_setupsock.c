/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping_setupsock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 17:28:47 by ulefebvr          #+#    #+#             */
/*   Updated: 2017/05/20 19:45:14 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

void	ping_setup_socket(int socket)
{
	struct timeval tv;

	tv.tv_sec = 1;
	tv.tv_usec = 0;
	if (env.interval < 1000) {
		tv.tv_sec = 0;
		tv.tv_usec = env.interval;
	}
	setsockopt(socket, SOL_SOCKET, SO_SNDTIMEO, (char*)&tv, sizeof(tv));

	env.ident = getpid();

	// set_signal(SIGINT, sigexit);
	// set_signal(SIGALRM, sigexit);
	// set_signal(SIGQUIT, sigstatus);

	gettimeofday(&env.start_time, NULL);
}
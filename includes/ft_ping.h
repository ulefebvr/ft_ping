/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:00:52 by ulefebvr          #+#    #+#             */
/*   Updated: 2017/05/20 20:31:20 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>

# define OPTIONS		"vh"
# define OPT_V			0x01
# define OPT_H			0x02

# define ADDRSTRLEN		INET_ADDRSTRLEN

# define DEFDATALEN		(64 - 8)
# define MAXIPLEN		60
# define MAXICMPLEN		76

typedef struct addrinfo	t_addrinfo;
typedef struct timeval	t_timeval;

typedef struct			s_env
{
	//OPTIONS
	int					options;
	int					count;
	int					interval;
	int					quiet;
	int					packetsize;
	int					ttl;
	int					deadline;
	int					timeout;
\
	char				*destination;
	int					socket;
	t_addrinfo			hints;
	t_addrinfo			*res;
	int					ident;
\
	int					datalen;
	int					optlen;
	t_timeval			start_time;
}						t_env;

t_env	env;

void	handle_signal(void);
void	ping_setup_socket(int socket);

int		createsocket(void);
int		ping_getaddrinfo(char *dest, t_addrinfo *hints, t_addrinfo **res);
int		ping4(t_addrinfo *ai);


int		ft_ping(void);

char	*ping_getipfromadress(char *destination);

#endif

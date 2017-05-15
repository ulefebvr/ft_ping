/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:00:52 by ulefebvr          #+#    #+#             */
/*   Updated: 2017/05/14 18:33:01 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include <arpa/inet.h>

# define OPTIONS		"vh"
# define OPT_V			0x01
# define OPT_H			0x02

# define ADDRSTRLEN		INET_ADDRSTRLEN

typedef struct		s_env
{
	//OPTIONS
	int				options;
	int				count;
	int				interval;
	int				quiet;
	int				packetsize;
	int				ttl;
	int				deadline;
	int				timeout;
\
	char			destination[ADDRSTRLEN];
}					t_env;

t_env	env;

int		ft_ping(int options, char *destination);

char	*ping_getipfromadress(char *destination);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:49:00 by ulefebvr          #+#    #+#             */
/*   Updated: 2017/05/14 18:01:52 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_ping.h"

int					ft_ping(int options, char *destination)
{
	printf("%s\n", destination);
	printf("v : %d\n", (options & OPT_V) != 0);
	printf("h : %d\n", (options & OPT_H) != 0);

	char *ip = ping_getipfromadress(destination);
	printf("%s --> %s\n", destination, ip);
	return (0);
}

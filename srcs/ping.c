/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:49:00 by ulefebvr          #+#    #+#             */
/*   Updated: 2017/05/13 17:49:17 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int					ft_ping(int options, char *destination)
{
	printf("%s\n", destination);
	printf("v : %d\n", (options & 1) != 0);
	printf("h : %d\n", (options & 2) != 0);
	return (0);
}

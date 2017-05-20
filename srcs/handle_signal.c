/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:36:12 by ulefebvr          #+#    #+#             */
/*   Updated: 2017/05/16 15:17:37 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void	quit(int x)
{
	(void)x;
	printf("\ncontrol C\n");
	exit(EXIT_SUCCESS);
}

void	handle_signal(void)
{
	signal(SIGINT, &quit);
}

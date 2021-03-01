/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:36:12 by selgrabl          #+#    #+#             */
/*   Updated: 2020/09/30 13:36:13 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	init_mutex(pthread_mutex_t *mutex, int nbr)
{
	int i;

	i = 0;
	while (i < nbr)
	{
		pthread_mutex_init(&mutex[i], NULL);
		++i;
	}
}

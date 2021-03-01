/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitoring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braimbau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:40:47 by braimbau          #+#    #+#             */
/*   Updated: 2020/09/29 14:40:48 by braimbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int			death_check(t_timeval last_time_eat, t_timeval t_now,
	t_philo *philo, t_timeval t_start)
{
	t_timeval	t_time;

	t_time = diff_time(last_time_eat, t_now);
	if (t_time.tv_sec * 1000000 + t_time.tv_usec >= philo->time_to_die)
	{
		sem_wait(philo->output);
		display(t_start, philo->number, "died");
		write(1, "End of simulation : one of the philosophers died\n", 49);
		philo->dead = 1;
		sem_post(philo->die);
		return (1);
	}
	return (0);
}

void		*monitoring(void *param)
{
	t_philo		*philo;
	t_timeval	t_now;
	t_timeval	t_start;

	philo = (t_philo*)param;
	t_start = philo->t_start;
	while (1)
	{
		gettimeofday(&t_now, NULL);
		t_now = diff_time(t_start, t_now);
		if ((int)philo->ntime_eat
			== philo->number_of_time_each_philosophers_must_eat)
			return (NULL);
		if (death_check(philo->last_time_eat, t_now, philo, t_start) == 1)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

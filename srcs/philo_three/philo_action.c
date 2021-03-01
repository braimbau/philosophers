/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braimbau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:40:41 by braimbau          #+#    #+#             */
/*   Updated: 2020/09/29 14:40:42 by braimbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		get_fork(t_philo *philo, t_timeval t_start)
{
	sem_wait(philo->mutext);
	sem_wait(philo->output);
	display(t_start, philo->number, "has taken a fork");
	sem_post(philo->output);
	sem_wait(philo->mutext);
	sem_wait(philo->output);
	display(t_start, philo->number, "has taken a fork");
	sem_post(philo->output);
}

void		release_fork(t_philo *philo)
{
	sem_post(philo->mutext);
	sem_post(philo->mutext);
}

void		eat(t_philo *philo, t_timeval t_start)
{
	sem_wait(philo->output);
	display(t_start, philo->number, "is eating");
	sem_post(philo->output);
	usleep(philo->time_to_eat);
}

void		psleep(t_philo *philo, t_timeval t_start)
{
	sem_wait(philo->output);
	display(t_start, philo->number, "is sleeping");
	sem_post(philo->output);
	usleep(philo->time_to_sleep);
	sem_wait(philo->output);
	display(t_start, philo->number, "is thinking");
	sem_post(philo->output);
}

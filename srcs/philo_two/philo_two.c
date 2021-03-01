/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braimbau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:22:36 by braimbau          #+#    #+#             */
/*   Updated: 2020/05/26 15:31:24 by raimbaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	copy_struct(t_philo *paste, t_philo copy)
{
	paste->number_of_philosopher = copy.number_of_philosopher;
	paste->number_of_time_each_philosophers_must_eat =
		copy.number_of_time_each_philosophers_must_eat;
	paste->time_to_die = copy.time_to_die;
	paste->time_to_eat = copy.time_to_eat;
	paste->time_to_sleep = copy.time_to_sleep;
	paste->t_start = copy.t_start;
	paste->output = copy.output;
}

int		check_status(t_philo philo, t_creat info)
{
	pthread_create(&info.win, NULL, &winner, &philo);
	pthread_create(&info.lose, NULL, &loser, &philo);
	while (1)
	{
		if (philo.dead == 1)
			return (1);
		else if (philo.dead == 2)
		{
			write(1, "End of simulation : philosophers ate enough times\n", 50);
			return (0);
		}
	}
}

void	setup_philo_launch(t_philo *philo, sem_t **mutext, t_creat *info)
{
	sem_unlink("/mutext");
	*mutext = sem_open("/mutext", O_CREAT, 0666, philo->number_of_philosopher);
	sem_unlink("/dead");
	philo->die = sem_open("/dead", O_CREAT, 0666, 1);
	sem_unlink("/output");
	philo->output = sem_open("/output", O_CREAT, 0666, 1);
	sem_wait(philo->die);
	gettimeofday(&philo->t_start, NULL);
	info->j = 0;
	philo->dead = 0;
}

int		create_start_philo(int nbr, t_philo philo)
{
	t_philo		arr[nbr];
	pthread_t	th[nbr];
	sem_t		*mutext;
	t_creat		info;

	setup_philo_launch(&philo, &mutext, &info);
	while (info.j < philo.number_of_philosopher)
	{
		copy_struct(&arr[info.j], philo);
		arr[info.j].dead = 0;
		arr[info.j].number = info.j;
		arr[info.j].die = philo.die;
		arr[info.j].mutext = mutext;
		pthread_create(&th[info.j], NULL, &ft_philosopher, &arr[info.j]);
		usleep(45);
		++info.j;
	}
	philo.th = (pthread_t*)&th;
	return (check_status(philo, info));
}

int		main(int argc, char **argv)
{
	t_philo philo;

	if (fill_and_error(&philo, argv, argc) == 1)
		return (1);
	return (create_start_philo(philo.number_of_philosopher, philo));
}

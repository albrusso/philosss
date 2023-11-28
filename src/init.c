/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:35:12 by albrusso          #+#    #+#             */
/*   Updated: 2023/11/21 14:39:27 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_data	*ft_init_data(int ac, char **av)
{
	t_data	*d;

	d = (t_data *)malloc(sizeof(t_data));
	if (!d || ft_check_args(ac, av) == 0)
		return (NULL);
	d->philo_nbr = ft_atoi(av[1]);
	d->time_die = ft_atoi(av[2]);
	d->time_eat = ft_atoi(av[3]);
	d->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		d->meal_nbr = ft_atoi(av[5]);
	else
		d->meal_nbr = -1;
	d->philo = (t_philo *)malloc(d->philo_nbr * sizeof(t_philo));
	if (!d->philo || ft_init_mutex_thread(d) == 0)
		return (NULL);
	return (d);
}

int	ft_init_mutex_thread(t_data *d)
{
	int	i;

	d->forks = (pthread_mutex_t *)malloc(d->philo_nbr
			* sizeof(pthread_mutex_t));
	d->threads = (pthread_t *)malloc(d->philo_nbr * sizeof(pthread_t));
	if (!d->forks || !d->threads)
		return (0);
	i = 0;
	while (i < d->philo_nbr)
	{
		d->philo[i] = ft_init_philo(i, d);
		pthread_mutex_init(&d->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&d->print, NULL);
	return (1);
}

t_philo	ft_init_philo(int i, t_data *d)
{
	t_philo	_philo;

	_philo.data_root = d;
	_philo.last_meal = 0;
	_philo.meal_counter = 0;
	_philo.philo_id = i + 1;
	return (_philo);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:30:29 by albrusso          #+#    #+#             */
/*   Updated: 2023/11/28 14:02:37 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_thread_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		pthread_detach(data->threads[i]);
		i++;
	}
}

int	ft_one_philo(t_data *d)
{
	pthread_mutex_lock(&d->forks[0]);
	pthread_mutex_lock(&d->print);
	printf("0 1 has taken fork\n");
	ft_usleep(d->time_die);
	printf("%ld 1 died\n", d->time_die);
	pthread_mutex_unlock(&d->print);
	pthread_mutex_unlock(&d->forks[0]);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac < 5 && ac > 6)
	{
		printf("To run use: ./philo [nbr_of_philo] [time_to_eat] ");
		printf("[time_to_sleep] ([nbr_of_meal])\n");
		return (1);
	}
	data = ft_init_data(ac, av);
	if (!data)
		return (2);
	if (data->philo_nbr == 1)
		return (ft_one_philo(data));
	ft_init_mutex_thread(data);
	ft_create_join_thread(data);
	ft_supervisor(data);
	ft_thread_destroy(data);
	return (0);
}

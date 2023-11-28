/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:00:16 by albrusso          #+#    #+#             */
/*   Updated: 2023/11/23 11:02:47 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_full_meal(t_data *d)
{
	int	i;

	if (d->meal_nbr == -1)
		return (1);
	i = 0;
	while (i < d->philo_nbr)
	{
		if (d->philo[i].meal_counter < d->meal_nbr)
			return (1);
		i++;
	}
	return (0);
}

int	ft_one_die(t_data *d)
{
	int		i;
	long	time_print;
	long	time_max;

	i = 0;
	while (i < d->philo_nbr)
	{
		time_max = d->philo[i].last_meal + d->time_die;
		time_print = ft_time_print();
		if (time_max + 10 < time_print)
		{
			pthread_mutex_lock(&d->print);
			printf("%ld %d %s\n", time_print, d->philo[i].philo_id, "died");
			pthread_mutex_unlock(&d->print);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_supervisor(t_data *d)
{
	while (1)
	{
		if (ft_full_meal(d) == 0)
			return ;
		if (ft_one_die(d) == 0)
			return ;
	}
}

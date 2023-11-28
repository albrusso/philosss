/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:09:48 by albrusso          #+#    #+#             */
/*   Updated: 2023/11/28 14:12:03 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_eat(t_philo *p)
{
	p->meal_counter++;
	p->last_meal = ft_time_print();
	ft_usleep(p->data_root->time_eat);
}

void	ft_set_forks(t_philo *p, int *f1, int *f2)
{
	int	_bool;

	if (p->philo_id % 2 == 0)
	{
		if (p->data_root->philo_nbr % 2 == 0)
			_bool = 0;
		else
			_bool = 1;
	}
	else
	{
		if (p->data_root->philo_nbr % 2 == 0)
			_bool = 1;
		else
			_bool = 0;
	}
	if (_bool == 0)
	{
		*f1 = (p->philo_id + 1) % (p->data_root->philo_nbr);
		*f2 = p->philo_id;
		return ;
	}
	*f1 = p->philo_id;
	*f2 = (p->philo_id + 1) % (p->data_root->philo_nbr);
}

void	ft_pick_forks(t_philo *p)
{
	int		f1;
	int		f2;

	ft_set_forks(p, &f1, &f2);
	pthread_mutex_lock(&p->data_root->forks[f1]);
	pthread_mutex_lock(&p->data_root->print);
	printf("%ld %d %s\n", ft_time_print(), p->philo_id, "has taken fork");
	pthread_mutex_unlock(&p->data_root->print);
	pthread_mutex_lock(&p->data_root->forks[f2]);
	pthread_mutex_lock(&p->data_root->print);
	printf("%ld %d %s\n", ft_time_print(), p->philo_id, "has taken fork");
	pthread_mutex_unlock(&p->data_root->print);
}

void	ft_drop_forks(t_philo *p)
{
	pthread_mutex_unlock(&p->data_root->forks[(p->philo_id + 1)
		% (p->data_root->philo_nbr)]);
	pthread_mutex_unlock(&p->data_root->forks[p->philo_id]);
}

void	*ft_routine(void *_philo)
{
	t_philo	*p;

	p = (t_philo *)_philo;
	if (p->philo_id % 2)
		ft_usleep(50);
	while (1)
	{
		ft_pick_forks(p);
		ft_eat(p);
		pthread_mutex_lock(&p->data_root->print);
		printf("%ld %d %s\n", ft_time_print(), p->philo_id, "is eating");
		pthread_mutex_unlock(&p->data_root->print);
		ft_drop_forks(p);
		ft_usleep(p->data_root->time_sleep);
		pthread_mutex_lock(&p->data_root->print);
		printf("%ld %d %s\n", ft_time_print(), p->philo_id, "is sleeping");
		pthread_mutex_unlock(&p->data_root->print);
	}
	return (NULL);
}

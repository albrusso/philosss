/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:59:35 by albrusso          #+#    #+#             */
/*   Updated: 2023/11/28 14:10:34 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_create_join_thread(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->philo_nbr)
	{
		if (pthread_create(&d->threads[i], NULL, ft_routine,
				(void *)&d->philo[i]) != 0)
			return ;
		i++;
	}
}

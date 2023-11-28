/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:16:14 by albrusso          #+#    #+#             */
/*   Updated: 2023/11/28 13:59:10 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* LIBRARYS */

# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/* STRUCTS */
struct	s_philo;
struct	s_data;

typedef struct s_philo
{
	struct s_data	*data_root;
	long			last_meal;
	int				philo_id;
	int				meal_counter;
}		t_philo;

typedef struct s_data
{
	int				philo_nbr;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	int				meal_nbr;
	struct s_philo	*philo;
	pthread_t		*threads;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;

}		t_data;

/* FUNCTION OF UTILS.C */
int			ft_atoi(const char *str);
int			ft_check_args(int ac, char **av);
long		ft_time_print(void);
long		ft_gettimeofday(void);
void		ft_usleep(long _time);

/* FUNTION OF INIT.C */
t_data		*ft_init_data(int ac, char **av);
int			ft_init_mutex_thread(t_data *d);
t_philo		ft_init_philo(int i, t_data *d);

/* FUNCTION OF THREAD.C */
void		ft_create_join_thread(t_data *d);

/* FUNCTION OF ROUTINE.C */
void		*ft_routine(void *_philo);
void		ft_drop_forks(t_philo *p);
void		ft_pick_forks(t_philo *p);
void		ft_set_forks(t_philo *p, int *f1, int *f2);
void		ft_eat(t_philo *p);

/* FUNCTION OF SUPERVISOR.C */
int			ft_full_meal(t_data *d);
int			ft_one_die(t_data *d);
void		ft_supervisor(t_data *d);

#endif
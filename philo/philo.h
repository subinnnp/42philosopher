/* ************************************************************************** */
/*                                                                            */
/*                                                       d :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:57:25 by siun              #+#    #+#             */
/*   Updated: 2023/11/06 22:57:25 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/types.h>
# include <semaphore.h>
# include <errno.h>

typedef struct s_philo
{
	int					index;
	int					state;
	int					life;
	int					last_moment_eat;
	pthread_t			thread;
	pthread_mutex_t		*r_chopstick;
	pthread_mutex_t		*l_chopstick;
	t_args				*args;
}				t_philo;

typedef struct s_args
{
	size_t		num_of_philo;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	int			eating_goal;
}				t_args;

int		ft_atoi(const char *nptr);
int		put_arguments(t_args *arg, char **input);
int 	philosopher(int *arg);
int		generate_threads(t_philo **philo, t_args args);
int		generate_chopstick(pthread_mutex_t **chopstick,
							t_philo **philo, t_args arg);
int		generate_philo(t_philo **philo, t_args args);
void    free_philo(t_philo **philo, t_args args);
void    free_philo_with_c(t_philo **philo, t_args args);
void	detach_threads(pthread_t *threads, int how_many);
size_t	get_current_time();
int		ft_usleep(size_t milliseconds);

#endif
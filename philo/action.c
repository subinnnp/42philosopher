/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:07:46 by subpark           #+#    #+#             */
/*   Updated: 2024/02/13 19:39:19 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	action_print(t_philo *philo, char *str)
{
	char	*timestamp;
	char	*num;

	pthread_mutex_lock(&(*philo->print_mu));
	timestamp = ft_itoa(get_current_time() - philo->args->start_time);
	if (!timestamp)
		return ;
	write(1, timestamp, ft_strlen(timestamp));
	free(timestamp);
	write(1, ": ", 2);
	num = ft_itoa(philo->index);
	if (!num)
		return ;
	write(1, num, ft_strlen(num));
	free(num);
	write(1, " ", 1);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	pthread_mutex_unlock(philo->print_mu);
}

void	philo_eats(t_philo *philo)
{
	pthread_mutex_lock(&(*philo->l_chopstick));
	action_print(philo, "has taken a fork");
	pthread_mutex_lock(&(*philo->r_chopstick));
	action_print(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->args->meal));
	action_print(philo, "is eating");
	philo->last_moment_eat = get_current_time();
	pthread_mutex_unlock(&(philo->args->meal));
	ft_usleep(philo->args->time_to_eat, *(philo->args));
	philo->num_of_meal ++;
	pthread_mutex_unlock(philo->l_chopstick);
	pthread_mutex_unlock(philo->r_chopstick);
}

void	philo_sleep(t_philo *philo)
{
	action_print(philo, "is sleeping");
	ft_usleep(philo->args->time_to_sleep, *(philo->args));//have to think about time to sleep more than 10 ms.
	if (get_current_time() - philo->last_moment_eat >= philo->args->time_to_die)
		philo->dead = 1;
}

void	philo_think(t_philo *philo)
{
	action_print(philo, "is thinking");
	if (get_current_time() - philo->last_moment_eat >= philo->args->time_to_die)
		philo->dead = 1;
}
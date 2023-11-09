/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:22:32 by siun              #+#    #+#             */
/*   Updated: 2023/11/09 14:48:10 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_philo **philo, t_args args)
{
	int i;

	i = 0;
	while (i < args.num_of_philo)
		free(philo[i ++]);
	return ;
}

void	free_philo_with_c(t_philo **philo, t_args args)
{
	int i;

	i = 0;
	while (i < args.num_of_philo)
	{
		pthread_mutex_destroy(philo[i]->l_chopstick);
		free(philo[i]->l_chopstick);
		free(philo[i]);
		i ++;
	}
	return ;
}

void	joining_threads(t_philo **philo, t_args args)
{
	int     i;
	int     res;
	void    *thread_result

	i = 0;
	while (i < args.num_of_philo)
	{
		res = pthread_join(philo[i]->thread, &thread_result);
		if (res != 0)
		{
			while (i < args.num_of_philo)
			{
				pthread_detach(philo[i]);
				i ++;
			}
			free_philo_with_c(philo, args);
			return ;
		}
		i ++;
	}
	free_philo_with_c(philo, args);
}
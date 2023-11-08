/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:55:24 by siun              #+#    #+#             */
/*   Updated: 2023/11/08 14:42:48 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosopher(int *arg)
{
	int	life;

	if (life == 0)
		return (0);
}

int	main(int argc, char **argv)
{
	t_args					args;
	t_philo					*philo;
	pthread_mutex_t			*chopstick;

	if (!put_arguments(&args, argv))
		return (errno);
	if (!generate_philo(&philo, args))
		return (errno);
	if (!generate_chopstick(&chopstick, &philo, args))
		return (errno);
	if (!generate_threads())

	return (0);
}
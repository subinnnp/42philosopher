/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:55:24 by siun              #+#    #+#             */
/*   Updated: 2023/11/09 17:48:02 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_checker(t_philo *first_philo)
{
	t_philo	*curr;
	int		i;

	curr = first_philo;
	i = 0;
	while (i < first_philo->arg.num_of_philo)
	{
		if (curr->dead)
			return (1);
		i ++;
	}
	return (0);
}

int	eating_checker(t_philo *first_philo)
{
	t_philo	*curr;
	int		i;

	if (first_philo->arg.eating_goal < 0)
		return (0);
	curr = first_philo;
	i = 0;
	while (i < first_philo->arg.num_of_philo)
	{
		if (philo->args.eating_goal != 0)
			return (0);
		curr = (curr + sizeof(t_philo));//not sure point. maybe have to do it as a linkedlist
	}
	return (1);
}

void	philosopher(t_philo *philo)
{
	if (philo->index % 2)
		ft_usleep(1);
	while (!philo->dead)
	{
		if (get_current_time() - philo->last_moment_eat >= time_to_die)
			philo->dead = 1;
		philo_eats(philo);
		if (philo->num_of_meal == philo->args.eating_goal)
			break ;
		philo_sleep(philo);
		philo_think(philo);
	}
	return ;
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
	if (!generate_threads(&philo, args))
		return (errno);
	if (dead_checker(philo) || eating_checker(philo))
		joining_threads(&philo, args);
	return (0);
}
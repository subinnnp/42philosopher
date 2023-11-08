/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:22:32 by siun              #+#    #+#             */
/*   Updated: 2023/11/08 14:42:46 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    free_philo(t_philo **philo, t_args args)
{
    int i;

    i = 0;
    while (i < args.num_of_philo)
        free(philo[i ++]);
    return ;
}

void    free_philo_with_c(t_philo **philo, t_args args)
{
    int i;

    i = 0;
    while (i < args.num_of_philo)
    {
        free(philo[i]->l_chopstick);
        free(philo[i]);
        i ++;
    }
    return ;
}
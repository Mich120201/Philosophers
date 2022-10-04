/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:31:05 by mvolpi            #+#    #+#             */
/*   Updated: 2022/10/04 11:40:39 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_file/philo.h"

void	*death(void *data)
{
	t_info	*info;
	int		i;

	info = data;
	while (1)
	{
		i = -1;
		while (++i < info->count_philo)
		{
			if (info->count_of_eat)
				if (info->philo[i].count_eat == info->count_of_eat)
					return (NULL);
			if (get_timestamp() - info->philo[i].last_eat
				> info->philo[i].time_to_die)
			{
				info->flag_of_death = 1;
				pthread_mutex_lock(&info->print);
				printf("%lld %d is died\n",
					get_timestamp() - info->philo[i].time_start,
					info->philo[i].id);
				return (NULL);
			}
		}
	}
	return (NULL);
}

void	*philo_life(void *data)
{
	t_philo	*philo;
	t_info	*info;

	philo = data;
	info = philo->info;
	if (philo->id % 2 == 0)
	{
		philo_print(info, philo, "is thinking");
		ft_usleep(50);
	}
	while (!info->flag_of_death)
	{
		if (info->count_of_eat)
			if (philo->count_eat == info->count_of_eat)
				return (NULL);
		if (eating(info, philo))
			return (NULL);
		sleeping(info, philo);
		thinking(info, philo);
	}
	return (NULL);
}

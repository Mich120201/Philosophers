/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:44:42 by mvolpi            #+#    #+#             */
/*   Updated: 2022/10/04 11:16:30 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_file/philo.h"

void	*death_time(void *dt)
{
	t_info	*info;
	int		i;

	info = dt;
	while (1)
	{
		i = -1;
		while (++i < info->c_philo)
		{
			if (info->c_eat)
				if (info->philo[i].count_eat == info->c_eat)
					return (NULL);
			if ((get_time() - info->philo[i].last_eat) \
				> info->philo[i].ttd)
			{
				info->flag_of_death = 1;
				pthread_mutex_lock(&info->print);
				printf("%lld %d is dead\n",
					get_time() - info->philo[i].time_start,
					info->philo[i].id);
				return (NULL);
			}
		}
	}
	return (NULL);
}

void	*time_life(void *dt)
{
	t_philo	*philo;
	t_info	*info;

	philo = dt;
	info = philo->info;
	if (philo->id % 2 == 0)
	{
		print_moves(info, philo, "is thinking\n");
		ft_sleep(50);
	}
	while (!info->flag_of_death)
	{
		if (info->c_eat)
			if (philo->count_eat == info->c_eat)
				return (NULL);
		if (is_eating(info, philo))
			return (NULL);
		is_sleeping(info, philo);
		is_thinking(info, philo);
	}
	return (NULL);
}

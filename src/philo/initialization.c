/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:30:25 by mvolpi            #+#    #+#             */
/*   Updated: 2022/10/10 10:29:20 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_file/philo.h"

t_info	*init_info(int ac, char **av)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->count_philo = ft_atoi(av[1]);
	info->count_of_eat = 0;
	if (ac == 6)
		info->count_of_eat = ft_atoi(av[5]);
	info->flag_of_death = 0;
	info->time_start = 0;
	info->thread = NULL;
	info->fork = NULL;
	pthread_mutex_init(&info->print, NULL);
	info->philo = NULL;
	return (info);
}

int	create_info(t_info *info)
{
	info->thread = malloc(sizeof(pthread_t) * info->count_philo);
	if (!info->thread)
		return (1);
	info->fork = malloc(sizeof(pthread_mutex_t) * info->count_philo);
	if (!info->fork)
		return (1);
	info->philo = malloc(sizeof(t_philo) * info->count_philo);
	if (!info->philo)
		return (1);
	return (0);
}

int	init_philo(t_info *info, char **av)
{
	int	i;

	i = -1;
	while (++i < info->count_philo)
	{
		info->philo[i].id = i + 1;
		info->philo[i].time_to_die = ft_atoi(av[2]);
		info->philo[i].time_to_eat = ft_atoi(av[3]);
		info->philo[i].time_to_sleep = ft_atoi(av[4]);
		info->philo[i].count_eat = 0;
		info->philo[i].left_fork = i;
		if (i < info->count_philo - 1)
			info->philo[i].right_fork = i + 1;
		else
			info->philo[i].right_fork = 0;
		info->philo[i].time_start = 0;
		info->philo[i].last_eat = 0;
		info->philo[i].info = info;
	}
	i = -1;
	while (++i < info->count_philo)
		if (pthread_mutex_init(&info->fork[i], NULL))
			return (1);
	return (0);
}

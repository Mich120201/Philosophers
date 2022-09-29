/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:34:40 by mvolpi            #+#    #+#             */
/*   Updated: 2022/09/28 12:33:45 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_file/philo.h"

t_info	*initalization_info(int ac, char **av)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		retunr (NULL);
	info->c_philo = ft_atoi(av[1]);
	info->c_eat = 0;
	if (ac == 6)
		info->c_eat = ft_atoi(av[5]);
	info->flag_of_death = 0;
	info->philo = NULL;
	info->fork = NULL;
	pthread_mutex_init(&info->print, NULL);
	info->thread = NULL;
	return (info);
}

int	creat_philosophers(t_info *info)
{
	info->thread = malloc(sizeof(pthread_t) * info->c_philo);
	if (!info->thread)
		return (1);
	info->fork = malloc(sizeof(pthread_mutex_t) * info->c_philo);
	if (!info->fork)
		return (1);
	info->philo = malloc(sizeof(t_philo) * info->c_philo);
	if (!info->philo)
		return (1);
	return (0);
}

int	initialization_philosophers(t_info *info, char **av)
{
	int	i;

	i = -1;
	while (++i < info->c_philo)
	{
		info->philo[i].id = i + 1;
		info->philo[i].ttd = ft_atoi(av[2]);
		info->philo[i].tte = ft_atoi(av[3]);
		info->philo[i].tts = ft_atoi(av[4]);
		info->philo[i].count_eat = 0;
		info->philo[i].l_fork = i;
		if (i < info->c_philo - 1)
			info->philo->r_fork = i + 1;
		else
			info->philo[i].r_fork = 0;
		info->philo[i].time_start = 0;
		info->philo[i].last_eat = 0;
		info->philo[i].info = info;
	}
	i = -1;
	while (++i < info->c_philo)
		if (pthread_mutex_init(&info->fork[i], NULL))
			return (1);
	return (0);
}

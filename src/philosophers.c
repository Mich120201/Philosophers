/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:24:16 by mvolpi            #+#    #+#             */
/*   Updated: 2022/10/10 10:29:15 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/philo.h"

void	start_progm(t_info *info)
{
	int			i;
	pthread_t	check;

	i = -1;
	info->time_start = get_time();
	while (++i < info->count_philo)
	{
		info->philo[i].time_start = info->time_start;
		info->philo[i].last_eat = info->time_start;
	}
	i = -1;
	while (++i < info->count_philo)
		pthread_create(&info->thread[i], NULL, &time_life, &info->philo[i]);
	pthread_create(&check, NULL, &death_time, info);
	pthread_mutex_unlock(&info->print);
	pthread_join(check, NULL);
	i = -1;
	while (++i < info->count_philo)
		pthread_join(info->thread[i], NULL);
}

int	main(int ac, char **av)
{
	t_info	*info;

	errors(ac, av);
	info = init_info(ac, av);
	if (!info)
		return (1);
	if (create_info(info))
		return (free_info(info));
	if (init_philo(info, av))
		return (free_info(info));
	start_progm(info);
	destroy_mutex(info);
	free_info(info);
	return (0);
}

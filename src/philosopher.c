/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:32:41 by mvolpi            #+#    #+#             */
/*   Updated: 2022/09/29 10:45:08 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/philo.h"

void	start_program(t_info *info)
{
	int			i;
	pthread_t	check;

	i = -1;
	info->s_time = get_time();
	while (++i < info->c_philo)
	{
		info->philo[i].time_start = info->s_time;
		info->philo[i].last_eat = info->s_time;
	}
	i = -1;
	while (++i < info->c_philo)
		pthread_create(&info->thread[i], NULL, &time_life, &info->philo[i]);
	pthread_create(&check, NULL, &death_time, info);
	pthread_mutex_unlock(&info->print);
	pthread_join(check, NULL);
	i = -1;
	while (++i < info->c_philo)
		pthread_join(info->thread[i], NULL);
}

int	main(int ac, char **av)
{
	t_info	*info;

	errors(ac, av);
	info = initialization_info(ac, av);
	if (!info)
		return (1);
	if (create_philosophers(info))
		return (free_info(info));
	if (initialization_philosophers(info, av))
		return (free_info(info));
	start_program(info);
	destroy_mutex(info);
	free_info(info);
	return (0);
}

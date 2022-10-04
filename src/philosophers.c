/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:24:16 by mvolpi            #+#    #+#             */
/*   Updated: 2022/10/04 11:51:23 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/philo.h"

void	start(t_info *info)
{
	int			i;
	pthread_t	check;

	i = -1;
	info->time_start = get_timestamp();
	while (++i < info->count_philo)
	{
		info->philo[i].time_start = info->time_start;
		info->philo[i].last_eat = info->time_start;
	}
	i = -1;
	while (++i < info->count_philo)
		pthread_create(&info->thread[i], NULL, &philo_life, &info->philo[i]);
	pthread_create(&check, NULL, &death, info);
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
	if (malloc_philo(info))
		return (ft_free(info));
	if (init_philo(info, av))
		return (ft_free(info));
	start(info);
	ft_destroy_mutex(info);
	ft_free(info);
	return (0);
}

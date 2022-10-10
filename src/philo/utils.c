/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:32:51 by mvolpi            #+#    #+#             */
/*   Updated: 2022/10/10 10:24:10 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_file/philo.h"

long long	get_time(void)
{
	struct timeval	t;
	long long		now;

	gettimeofday(&t, NULL);
	now = ((t.tv_sec * 1000) + (t.tv_usec / 1000));
	return (now);
}

int	free_info(t_info *info)
{
	if (info->philo)
		free(info->philo);
	if (info->fork)
		free(info->fork);
	if (info->thread)
		free(info->thread);
	free(info);
	return (1);
}

void	destroy_mutex(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->count_philo)
		if (pthread_mutex_destroy(&info->fork[i]))
			printf("Error: Destroyed mutex %d.\n", i);
	pthread_mutex_destroy(&info->print);
}

void	ft_usleep(long long time)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}

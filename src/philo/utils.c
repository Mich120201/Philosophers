/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:02:14 by mvolpi            #+#    #+#             */
/*   Updated: 2022/09/29 12:22:34 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_file/philo.h"

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
	while (++i < info->c_philo)
		if (pthread_mutex_destroy(&info->fork[i]))
			ft_printf("Error!! the mutex %d was destroyed!!\n", i);
	pthread_mutex_destroy(&info->print);
}

void	ft_sleep(long long time)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}

long	atoilong(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return ((res * sign));
}

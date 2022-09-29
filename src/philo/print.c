/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:42:14 by mvolpi            #+#    #+#             */
/*   Updated: 2022/09/29 12:08:14 by mvolpi           ###   ########.fr       */
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

void	print_moves(t_info *info, t_philo *philo, char *str)
{
	if (info->flag_of_death)
		return ;
	pthread_mutex_lock(&info->print);
	if (info->flag_of_death)
		return ;
	ft_printf("%lld %d %s",
		get_time() - philo->time_start, philo->id, str);
	pthread_mutex_unlock(&info->print);
}

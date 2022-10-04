/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:32:18 by mvolpi            #+#    #+#             */
/*   Updated: 2022/10/04 11:40:21 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_file/philo.h"

void	philo_print(t_info	*info, t_philo *philo, char *str)
{
	if (info->flag_of_death)
		return ;
	pthread_mutex_lock(&info->print);
	if (info->flag_of_death)
		return ;
	printf("%lld %d %s\n",
		get_timestamp() - philo->time_start, philo->id, str);
	pthread_mutex_unlock(&info->print);
}

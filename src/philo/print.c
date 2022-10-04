/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:42:14 by mvolpi            #+#    #+#             */
/*   Updated: 2022/10/04 11:19:08 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_file/philo.h"

void	print_moves(t_info *info, t_philo *philo, char *str)
{
	if (info->flag_of_death)
		return ;
	pthread_mutex_lock(&info->print);
	if (info->flag_of_death)
		return ;
	printf("%lld %d %s",
		get_time() - philo->time_start, philo->id, str);
	pthread_mutex_unlock(&info->print);
}

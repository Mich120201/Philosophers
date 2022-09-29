/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:07:47 by mvolpi            #+#    #+#             */
/*   Updated: 2022/09/29 12:26:53 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_file/philo.h"

int	is_eating(t_info *info, t_philo *philo)
{
	if (info->flag_of_death)
		return (1);
	if (philo->l_fork < philo->r_fork)
		pthread_mutex_lock(&info->fork[philo->l_fork]);
	else
		pthread_mutex_lock(&info->fork[philo->r_fork]);
	print_moves(info, philo, "has taken a fork");
	if (info->c_philo == 1)
	{
		pthread_mutex_unlock(&info->fork[info->philo->l_fork]);
		return (1);
	}
	if (philo->l_fork < philo->r_fork)
		pthread_mutex_lock(&info->fork[philo->l_fork]);
	else
		pthread_mutex_lock(&info->fork[philo->r_fork]);
	print_moves(info, philo, "has taken a fork");
	print_moves(info, philo, "is eating");
	philo->count_eat++;
	philo->last_eat = get_time();
	ft_sleep(philo->tte);
	pthread_mutex_unlock(&info->fork[philo->l_fork]);
	pthread_mutex_unlock(&info->fork[philo->r_fork]);
	return (0);
}

void	is_sleeping(t_info *info, t_philo *philo)
{
	if (info->flag_of_death)
		return ;
	print_moves(info, philo, "is sleeping");
}

void	is_thinking(t_info *info, t_philo *philo)
{
	if (info->flag_of_death)
		return ;
	print_moves(info, philo, "is thiking");
}

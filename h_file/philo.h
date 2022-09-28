/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:33:25 by mvolpi            #+#    #+#             */
/*   Updated: 2022/09/28 10:57:10 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include "../libft/h_file/libft.h"

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_philo
{
	int			id;
	int			ttd;
	int			tte;
	int			tts;
	int			count_eat;
	int			fork;
	long long	time_start;
}	t_philo;

typedef struct s_info
{
	int				count_philo;
	int				flag_of_death;
	pthread_t		*thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	t_philo			*philo;
}	t_info;

void	errors(int ac, char **av);
int		main(int ac, char **av);
long	atoilong(const char *str);

#endif

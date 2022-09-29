/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:33:25 by mvolpi            #+#    #+#             */
/*   Updated: 2022/09/29 12:25:27 by mvolpi           ###   ########.fr       */
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

typedef struct s_philo
{
	int				id;
	int				ttd;
	int				tte;
	int				tts;
	int				count_eat;
	int				l_fork;
	int				r_fork;
	long long		time_start;
	long long		last_eat;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	int				c_philo;
	int				c_eat;
	int				flag_of_death;
	long long		s_time;
	pthread_t		*thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	t_philo			*philo;
}	t_info;

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

/*src*/
int			main(int ac, char **av);
void		start_program(t_info *info);
	/*philo*/
		/*errors*/
void		errors(int ac, char **av);
		/*initialization*/
t_info		*initialization_info(int ac, char **av);
int			create_philosophers(t_info *info);
int			initialization_philosophers(t_info *info, char **av);
		/*life*/
void		*death_time(void *dt);
void		*time_life(void *dt);
		/*moves*/
int			is_eating(t_info *info, t_philo *philo);
void		is_sleeping(t_info *info, t_philo *philo);
void		is_thinking(t_info *info, t_philo *philo);
		/*print*/
long long	get_time(void);
void		print_moves(t_info *info, t_philo *philo, char *str);
		/*utils*/
int			free_info(t_info *info);
void		destroy_mutex(t_info *info);
void		ft_sleep(long long time);
long		atoilong(const char *str);

#endif

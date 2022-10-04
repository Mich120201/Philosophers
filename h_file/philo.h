/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:23:05 by mvolpi            #+#    #+#             */
/*   Updated: 2022/10/04 11:59:21 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				count_eat;
	int				left_fork;
	int				right_fork;
	long long		time_start;
	long long		last_eat;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	int				count_philo;
	int				count_of_eat;
	int				flag_of_death;
	long long		time_start;
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

//utils
long long	ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
int			ft_isdigit(int c);
long		atoilong(const char *str);
long long	get_timestamp(void);
int			ft_free(t_info *info);
void		ft_destroy_mutex(t_info *info);
void		ft_usleep(long long time);

//init
t_info		*init_info(int ac, char **av);
int			errors(int ac, char **av);
int			malloc_philo(t_info *info);
int			init_philo(t_info *info, char **av);

//philo
void		philo_print(t_info	*info, t_philo *philo, char *str);
int			eating(t_info *info, t_philo *philo);
void		sleeping(t_info *info, t_philo *philo);
void		thinking(t_info *info, t_philo *philo);

//main
void		start(t_info *info);
void		*philo_life(void *data);
void		*death(void *data);

#endif

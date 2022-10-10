/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:23:05 by mvolpi            #+#    #+#             */
/*   Updated: 2022/10/10 10:56:55 by mvolpi           ###   ########.fr       */
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

/*errors*/
int			errors(int ac, char **av);

/*ft_split*/
int			ft_is_separator(char c, char cr);
int			ft_words(char *str, char c);
void		ft_write_word(char *dest, char *src, char c);
int			ft_write_split(char **split, char *str, char c);
char		**ft_split(char const *s, char c);

/*initialization*/
t_info		*init_info(int ac, char **av);
int			create_info(t_info *info);
int			init_philo(t_info *info, char **av);

/*life*/
void		*death_time(void *dt);
void		*time_life(void *dt);

/*moves*/
int			is_eating(t_info *info, t_philo *philo);
void		is_sleeping(t_info *info, t_philo *philo);
void		is_thinking(t_info *info, t_philo *philo);

/*print*/
void		print_moves(t_info	*info, t_philo *philo, char *str);

/*utils_2*/
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
long		atoilong(const char *str);

/*utils*/
long long	get_time(void);
void		free_str(char **str);
int			free_info(t_info *info);
void		destroy_mutex(t_info *info);
void		ft_usleep(long long time);

/*philosopher*/
void		start_progm(t_info *info);
int			main(int ac, char **av);

#endif

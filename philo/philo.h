/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:05:54 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/14 15:42:07 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <stdlib.h>	//malloc, free
# include <string.h>	//memset
# include <stdio.h>		//stdio
# include <unistd.h>	//write, usleep
# include <sys/time.h>	//gettimeofday
# include <pthread.h>	//threads : create, detach, join
						//mutexes : init, destroy, lock, unlock

#ifndef STDIN
# define STDIN 0
#endif

#ifndef STDOUT
# define STDOUT 1
#endif

#ifndef STDERR
# define STDERR 2
#endif

typedef enum e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef enum e_state
{
	DEAD,
	HAS_1_FORK,
	HAS_2_FORK,
	THINKING,
	SLEEPING,
	EATING
}				t_state;

typedef struct s_fork
{
	long			id;
	pthread_mutex_t	state;
}				t_fork;

typedef struct s_philo
{
	long			id;
	long			meals;
	long			last_meal;
	t_state			state;
	t_fork			*f_left;
	t_fork			*f_right;
	pthread_t		thread_id;
}				t_philo;

typedef struct s_data
{
	long	nb_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	meals_limit;
	int		*tab;
	t_bool	end;
	t_fork	**forks;
	t_philo	*philos;
}				t_data;

// Parsing
t_data	*parse_arguments(int argc, char **argv);
t_bool	init_forks(t_data *data);
t_bool	init_philos(t_data *data);
// Utils
void	ft_putstr_fd(int fd, char *message);
t_bool	ft_isdigit(char c);
long	ft_atol(const char *str);
void	ft_clean(t_data *data);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:57:46 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/16 23:02:26 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h> //memset
# include <stdio.h> //printf
# include <stdlib.h> //malloc, free
# include <unistd.h> //write, usleep
# include <sys/time.h> //gettimeofday
# include <pthread.h> //threads, mutexes

typedef struct s_table t_table;

typedef enum e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef	struct s_philo
{
	t_table		*table;
	pthread_t	thread;
	int			id;
	int			meals;
	long		last_meal;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}				t_philo;

typedef struct s_table
{
	long			n_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			n_meals;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}				t_table;

t_bool	check_parameters(int argc, char **argv);
t_table	*parsing(int argc, char **argv);
long	ft_atol(char *str);
void	destroy_forks(t_table *table);

#endif
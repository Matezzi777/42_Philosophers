/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 21:08:21 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/16 23:05:26 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	init_forks(t_table *table)
{
	int				i;
	pthread_mutex_t	*forks;

	forks = (pthread_mutex_t *)malloc(table->n_philos * sizeof(pthread_mutex_t));
	if (!forks)
		return (FALSE);
	i = -1;
	while (++i < table->n_philos)
	{
		if (pthread_mutex_init(&(forks[i]), NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&(forks[i]));
			return (free(forks), FALSE);
		}
	}
	table->forks = forks;
	return (TRUE);
}

static t_bool	init_philos(t_table *table)
{
	int		i;
	t_philo	*philos;

	philos = (t_philo *)malloc(table->n_philos * sizeof(t_philo));
	if (!philos)
		return (FALSE);
	i = -1;
	while (++i < table->n_philos)
	{
		philos[i].table = table;
		philos[i].id = i;
		philos[i].meals = 0;
		philos[i].last_meal = 0;
		philos[i].left = &(table->forks[i]);
		if (i < table->n_philos - 1)
			philos[i].right = &(table->forks[i + 1]);
		else
			philos[i].right = &(table->forks[0]);
	}
	table->philos = philos;
	return (TRUE);
}

t_table	*parsing(int argc, char **argv)
{
	t_table	*table;

	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->n_philos = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		table->n_meals = ft_atol(argv[5]);
	else
		table->n_meals = 0;
	if (pthread_mutex_init(&(table->print), NULL))
		return (free(table), NULL);
	if (!init_forks(table))
		return (pthread_mutex_destroy(&(table->print)), free(table), NULL);
	if (!init_philos(table))
		return (destroy_forks(table), pthread_mutex_destroy(&(table->print)),
			free(table), NULL);
	return (table);
}

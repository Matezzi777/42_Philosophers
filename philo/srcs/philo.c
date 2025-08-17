/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:14:49 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/17 18:45:49 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	pthread_mutex_lock(&(philo->table->print));
	printf("Hello from Philo number %d.", philo->id);
	pthread_mutex_unlock(&(philo->table->print));
	return (NULL);
}

void	start_simulation(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->n_philos)
		pthread_create(&(table->philos[i].thread), NULL, &philo_routine,
			&(table->philos[i]));
	i = -1;
	while (++i < table->n_philos)
		pthread_join(table->philos[i].thread, NULL);
}
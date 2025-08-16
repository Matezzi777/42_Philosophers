/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:18:02 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/16 23:02:12 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_forks(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->n_philos)
		pthread_mutex_destroy(&(table->forks[i]));
}

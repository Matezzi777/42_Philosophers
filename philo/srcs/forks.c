/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:28:43 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/14 16:55:28 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	init_forks(t_data *data)
{
	int	i;
	t_fork	*elem;
	t_fork	**forks;

	forks = (t_fork **)malloc(data->nb_philos * sizeof(t_fork *));
	if (!forks)
		return (FALSE);
	i = -1;
	while (++i < data->nb_philos)
	{
		elem = (t_fork *)malloc(sizeof(t_fork));
		if (!elem)
			return (FALSE);
		elem->id = i;
		elem->state = ...;
	}
	return (TRUE);
}

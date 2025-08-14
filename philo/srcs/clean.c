/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:30:13 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/14 16:51:17 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

ft_clean(t_data *data)
{
	int	i;

	if (data->forks)
	{
		i = 0;
		while (i < data->nb_philos && data->forks[i])
			free(data->forks[i++]);
		free(data->forks);
	}
	if (data->philos)
	{
		i = 0;
		while (i < data->nb_philos && data->philos[i])
			free(data->philos[i++]);
		free(data->philos);
	}
	free(data);
}

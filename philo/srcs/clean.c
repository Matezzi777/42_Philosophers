/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:30:13 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/14 15:42:04 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

ft_clean(t_data *data)
{
	int	i;

	if (data->forks)
	{
		i = -1;
		while (++i < data->nb_philos)
			free(data->forks[i]);
	}
	if (data->tab)
	{
		i = -1;
		while (++i < 10)
			free(data->tab[i]);
	}
	free(data);
}

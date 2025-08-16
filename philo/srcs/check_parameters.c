/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 21:09:59 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/16 21:41:09 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	is_pos_long(char *number)
{
	int	i;

	i = -1;
	while (number[++i])
	{
		if (!('0' <= number[i] && number[i] <= '9'))
			return (FALSE);
		if (i > 18)
			return (FALSE);
	}
	return (TRUE);
}

t_bool	check_parameters(int argc, char **argv)
{
	int	i;

	if (argc < 5)
		return (printf("Too few arguments.\nUse : ./philo <n_philos> "
				"<time_to_die> <time_to_eat> <time_to_sleep> "
				"[meals_needed]\n"), FALSE);
	if (argc > 6)
		return (printf("Too many arguments.\nUse : ./philo <n_philos> "
				"<time_to_die> <time_to_eat> <time_to_sleep> "
				"[meals_needed]\n"), FALSE);
	i = 0;
	while (++i < argc)
		if (!is_pos_long(argv[i]) || ft_atol(argv[i]) <= 0)
			return (printf("Argument %d is not a non-null positive "
					"long integer.\n", i), FALSE);
	return (TRUE);
}

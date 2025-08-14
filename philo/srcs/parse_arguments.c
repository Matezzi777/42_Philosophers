/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:39:40 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/14 15:30:05 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Check if a string is represents a long integer.
	Accept one unic '+' sign at the start of the number.
	Does not accept negative numbers.
*/
static t_bool	is_long(char *number)
{
	int				i;
	int				n_digits;
	unsigned long	result;

	i = 0;
	if (!number || !number[0])
		return (FALSE);
	while (number[i] == ' ' || number[i] == '\t')
		i++;
	if (number[i] == '+')
		i++;
	n_digits = 0;
	result = 0;
	while (ft_isdigit(number[i + n_digits]))
	{
		result = result * 10 + number[i + n_digits] - '0';
		n_digits++;
	}
	if (result > LONG_MAX)
		return (FALSE);
	if (number[i + n_digits] || n_digits > 19)
		return (FALSE);
	return (TRUE);
}

/*
	Check if all the parameters are valid long numbers.
*/
static t_bool	check_parameters(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!is_long(argv[i]))
			return (ft_putstr_fd(STDOUT, "An argument is not a long integer value.\n"), FALSE);
		else
			ft_putstr_fd(STDOUT, "Valid long integer value.\n");
	}
	return (TRUE);
}

/*
	Initialize the t_data structure depending on the arguments passed.
	Return NULL if the arguments are not correct or if a malloc error happens.
*/
t_data	*parse_arguments(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5)
		return (ft_putstr_fd(STDOUT, "Too few arguments.\n"), NULL);
	if (argc > 6)
		return (ft_putstr_fd(STDOUT, "Too many arguments.\n"), NULL);
	if (!check_parameters(argc, argv))
		return (NULL);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (ft_putstr_fd(STDOUT, "t_data malloc failed.\n"), NULL);
	data->nb_philos = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	data->meals_limit = -1;
	if (argc == 6)
		data->meals_limit = ft_atol(argv[5]);
	data->end = FALSE;
	if (!init_forks(data) || !init_philos(data))
		return (ft_clean(data), NULL);
	return (data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:56:34 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/17 18:35:42 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void	draw_philo(int n, t_philo *philo)
// {
// 	printf("Philosopher %d   : %p\n", n, philo);
// 	printf("	ID           : %d\n", philo->id);
// 	printf("	Table        : %p\n", philo->table);
// 	printf("	Meals        : %d\n", philo->meals);
// 	printf("	Last meal    : %ld\n", philo->last_meal);
// 	printf("	Left fork    : %p\n", philo->left);
// 	printf("	Right fork   : %p\n\n", philo->right);
// }

// static void	draw_table(t_table *table)
// {
// 	int	i;

// 	printf("================ TABLE ===============\n");
// 	printf("Table address    : %p\n", table);
// 	printf("Number of philos : %ld\n", table->n_philos);
// 	printf("time_to_die      : %ld\n", table->time_to_die);
// 	printf("time_to_eat      : %ld\n", table->time_to_eat);
// 	printf("time_to_sleep    : %ld\n", table->time_to_sleep);
// 	printf("Meals needed     : %ld\n", table->n_meals);
// 	printf("Print Mutex      : %p\n", &(table->print));
// 	printf("\n================ FORKS ================\n");
// 	i = -1;
// 	while (++i < table->n_philos)
// 		printf("Fork %d Mutex : %p\n", i, &(table->forks[i]));
// 	printf("\n============ PHILOSOPHERS =============\n");
// 	i = -1;
// 	while (++i < table->n_philos)
// 		draw_philo(i + 1, &(table->philos[i]));
// 	printf("======================================\n");
// }

int	main(int argc, char **argv)
{
	t_table	*table;

	if (!check_parameters(argc, argv))
		return (0);
	// printf("Valid arguments.\n");
	table = parsing(argc, argv);
	if (!table)
		return (0);
	start_simulation(table);
	clean_exit(table);
}

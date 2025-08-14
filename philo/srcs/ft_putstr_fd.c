/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:34:17 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/14 13:36:49 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Write a message in the given file descriptor.
*/
void	ft_putstr_fd(int fd, char *message)
{
	int	i;

	i = -1;
	while (message[++i])
		write(fd, &message[i], 1);
}

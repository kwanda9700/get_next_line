/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilekwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:00:51 by ksilekwa          #+#    #+#             */
/*   Updated: 2019/06/06 12:01:55 by ksilekwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Recreation of the ft_putnbr_fd function.
** The same as putnbr except we output to a
** file desciptor instead of to the standard output.
*/

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

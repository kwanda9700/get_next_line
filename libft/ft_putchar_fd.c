/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilekwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 11:56:43 by ksilekwa          #+#    #+#             */
/*   Updated: 2019/06/06 11:57:32 by ksilekwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Recreation of the putchar_fd function.
** The same as putchar except we output to a
** file descriptor instead of to the standard output.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

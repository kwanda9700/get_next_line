/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilekwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 11:59:09 by ksilekwa          #+#    #+#             */
/*   Updated: 2019/06/05 12:00:05 by ksilekwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 65535

typedef struct			s_listgnl
{
	char				*text;
	char				*lnew;
	struct s_listgnl	*next;
	int					fd;
}						t_listgnl;

int						get_next_line(int const fd, char **line);

#endif

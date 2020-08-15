/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 22:57:08 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/13 17:58:56 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			check_new_or_no(int fd, char *str[])
{
	if (str[fd] == NULL)
		str[fd] = ft_strnew(0);
}

int				next_mod(int fd, char *str[], char **line)
{
	size_t		str_len;
	char		*t_var;

	str_len = 0;
	if (*str[fd] == '\0')
	{
		ft_memdel((void**)&str[fd]);
		return (0);
	}
	while (!((str[fd][str_len] == '\0') || (str[fd][str_len] == '\n')))
		str_len++;
	*line = ft_strsub(str[fd], 0, str_len);
	t_var = ft_strdup(str[fd] + str_len + 1);
	ft_memdel((void **)&str[fd]);
	str[fd] = ft_strdup(t_var);
	ft_memdel((void **)&t_var);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		stock[BUFF_SIZE + 1];
	char		*t_var;
	static char	*str[MAX_FD];
	int			read_b;

	if (fd < 0 || fd > MAX_FD || !line || (read(fd, stock, 0) < 0))
		return (-1);
	check_new_or_no(fd, str);
	while (ft_strchr(str[fd], '\n') == 0)
	{
		read_b = read(fd, stock, BUFF_SIZE);
		if (read_b == 0 && *str[fd] != '\0')
		{
			t_var = str[fd];
			str[fd] = ft_strjoin(t_var, "\n");
			ft_memdel((void **)&t_var);
		}
		if (read_b == 0)
			break ;
		stock[read_b] = '\0';
		t_var = str[fd];
		str[fd] = ft_strjoin(t_var, stock);
		ft_memdel((void **)&t_var);
	}
	return (next_mod(fd, str, line));
}

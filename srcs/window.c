/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:10:45 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/11 09:36:18 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int					print_size_window(t_ft_select *s)
{
	struct winsize	size;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) < 0)
	   exit_ft_select(s, "ERROR. window.c 20", FAIL);	
	ft_printf("->%d\n->%d\n", size.ws_row, size.ws_col);
	return (0);
}

int					get_win_row(t_ft_select *s)
{
	struct winsize	size;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) < 0)
	   exit_ft_select(s, "ERROR. window.c 40", FAIL);	
	return (size.ws_row);
}

int					get_win_col(t_ft_select *s)
{
	struct winsize	size;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) < 0)
	   exit_ft_select(s, "ERROR. window.c 40", FAIL);	
	return (size.ws_col);
}

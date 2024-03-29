/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 01:05:03 by                   #+#    #+#             */
/*   Updated: 2019/07/10 17:47:47 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"


int			read_input(t_ft_select *s)
{
	long	buf;

	buf = 0;
	_TPUTS_TGETSTR(CLEAR_TERMINAL);
	prepare_output_elem(s);
	_TPUTS_TGETSTR(START_CURSOR_POS);
	while (!0 && buf != 27 && !(buf = 0))
		if (read(STDIN_FILENO, &buf, 4))
			handle_keys(s, buf);
	return (0);
}

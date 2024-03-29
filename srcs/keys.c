/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:58:28 by                   #+#    #+#             */
/*   Updated: 2019/07/11 17:49:02 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	move_right(t_ft_select *s)
{
	int		len;
	t_elem	**elem;

	elem = s->elem;
//	_CURSOR_PRT_POS(s);
	while (*elem && !((*elem)->is_pos))
		++elem;
	if (*elem)
		(*elem)->is_pos = 0;
	if (*(elem + 1) && ((*(elem + 1))->is_pos = 1))
	//	_CURSOR_SET_POS(s, (s->pos->pos_col) + 1, s->pos->pos_row);
		cursor_set_pos(s, (s->pos->pos_col) + 1, s->pos->pos_row);
	else
	{
		_TPUTS_TGETSTR(START_CURSOR_POS);
		cursor_set_pos(s, 0, 0);
		(*(s->elem))->is_pos = 1;
		return (0);
	}
	len = get_max_len_elem(s) + 1;
	while (--len >= 0)
		_TPUTS_TGETSTR(MOVE_RIGHT);
	return (0);
}

int			handle_keys(t_ft_select *s, long key)
{
	if (s && key)
	{
//		ft_printf("%\n%ld\n", key);
	}
	if (key == UP_KEY)
		_TPUTS_TGETSTR(MOVE_UP);
	else if (key == DOWN_KEY)
		_TPUTS_TGETSTR(MOVE_DOWN);
	else if (key == LEFT_KEY)
		_TPUTS_TGETSTR(MOVE_LEFT);
	else if (key == RIGHT_KEY)
		move_right(s);
	return (0);
}

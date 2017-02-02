/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:52:16 by bsouchet          #+#    #+#             */
/*   Updated: 2017/01/29 18:22:38 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		render_frame(t_rt *rt)
{
	int			i;
	t_thread	*th_curs;
	t_iter		*it_curs;

	i = -1;
	th_curs = rt->t;
	it_curs = rt->iter;
	while (++i < rt->m_thread)
	{
		set_thread(th_curs, rt, &(it_curs->x), &(it_curs->y), &(it_curs->s));
		th_curs = th_curs->next;
		it_curs = it_curs->next;
	}
	i = -1;
	th_curs = rt->t;
	while (++i < rt->m_thread && join_thread(th_curs))
		th_curs = th_curs->next;
	i = -1;
	th_curs = rt->t;
	while (++i < rt->m_thread && destroy_thread_attr(th_curs))
		th_curs = th_curs->next;
	fsdl_fill_rect(rt->s_rend, (SDL_Rect){0, 0, 1244, 586}, LOL_BG);
	fsdl_fps_limit(rt->fps);
	fsdl_fps_counter(rt->fps);
	draw_state_frame(rt);
	++rt->iter->s;
	rt->render = 1;
}

void		render_loop(t_rt *rt)
{
	while (rt->run)
		if (!rt->suspend)
			render_frame(rt);
	pthread_exit(NULL);
}

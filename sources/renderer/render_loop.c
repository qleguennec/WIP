/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:52:16 by bsouchet          #+#    #+#             */
/*   Updated: 2017/02/02 18:39:05 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		render_frame(t_rt *rt)
{
	fsdl_fill_rect(rt->s_rend, (SDL_Rect){0, 0, 1244, 586}, LOL_BG);
	fsdl_fps_limit(rt->fps);
	fsdl_fps_counter(rt->fps);
	draw_state_frame(rt);
	rt->render = 1;
}

void		render_loop(t_rt *rt)
{
	while (rt->run)
		if (!rt->suspend)
			render_frame(rt);
}

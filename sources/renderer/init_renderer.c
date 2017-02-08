/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:49:37 by bsouchet          #+#    #+#             */
/*   Updated: 2017/02/08 13:01:05 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	init_window_elements(t_rt *rt)
{
	rt->r_view = (SDL_Rect){232, 84, 816, 588};
	rt->r_info = (SDL_Rect){215, 690, 850, 30};
	rt->cursor[0] = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
	rt->cursor[1] = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
	rt->ui->s_ui = IMG_Load("./assets/images/ui_7.png");
	rt->ui->font[0] = TTF_OpenFont("./assets/font/SourceCodePro.ttf", 14);
	rt->ui->font[1] = TTF_OpenFont("./assets/font/SourceCodePro.ttf", 12);
	rt->s_back = SDL_GetWindowSurface(rt->win);
	rt->s_rend = SDL_CreateRGBSurfaceWithFormat(0, 1244, 588, 32, SDL_PF);
	rt->s_process = SDL_CreateRGBSurfaceWithFormat(0, 1244, 618, 32, SDL_PF);
	fsdl_fill_rect(rt->s_back, (SDL_Rect){0, 0, 1280, 720}, WIN_BG);
	rt->ui->s_ver = TTF_RenderText_Blended(rt->ui->font[0], WIN_VERSION,
	(SDL_Color){162, 162, 162, 255});
}

static void	init_fps_structure(t_rt *rt)
{
	rt->fps->limit = MAX_FPS;
	rt->fps->framelimit = 0;
	rt->fps->fps = 0;
	rt->fps->update = 0;
	rt->fps->current = 0;
}

void		init_renderer(t_rt *rt)
{
	rt->run = 1;
	rt->m_thread = 16;
	rt->suspend = 1;
	rt->n_info = 0;
	rt->t_info = 0;
	rt->s_elem = NULL;
	init_fps_structure(rt);
	fsdl_fps_limit(rt->fps);
	init_window_elements(rt);
	init_gui_structure(rt);
	draw_current_camera_name(rt, 0);
	draw_scene_parameters(rt);
	draw_renderer_info(rt);
	draw_outliner(rt, -1, 0);
	draw_info_bar(rt);
}

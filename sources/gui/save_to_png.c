/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_to_png.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 23:03:17 by bsouchet          #+#    #+#             */
/*   Updated: 2017/01/29 18:29:27 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	save_to_png_part2(t_rt *rt)
{
	rt->ui->tmp = ft_strjoin("temporary/", rt->ui->n_save, 'N');
	SDL_SaveBMP(rt->s_temp, rt->ui->tmp);
	rt->ui->tmp = ft_strjoin("sips -s format png ", rt->ui->tmp, 'R');
	rt->ui->tmp = ft_strjoin(rt->ui->tmp, " --out ", 'L');
	rt->ui->tmp = ft_strjoin(rt->ui->tmp, "saved_images/", 'L');
	rt->ui->tmp = ft_strjoin(rt->ui->tmp, ft_edit_end(rt->ui->n_save, ".png"), 'B');
	rt->ui->tmp = ft_strjoin(rt->ui->tmp, " 2&>/dev/null >/dev/null", 'L');
	system(rt->ui->tmp);
	free(rt->ui->tmp);
	rt->ui->tmp = ft_strjoin("temporary/", rt->ui->n_save, 'R');
	rt->ui->tmp = ft_strjoin("rm ", rt->ui->tmp, 'R');
	system(rt->ui->tmp);
	free(rt->ui->tmp);
	SDL_FreeSurface(rt->s_temp);
}

void		save_to_png(t_rt *rt)
{
	static int	id = 1;

	rt->s_temp = SDL_ConvertSurfaceFormat(rt->s_rend, SDL_PIXELFORMAT_RGB24, 0);
	if (id == 1)
		system("mkdir -p saved_images");
	rt->ui->tmp = ft_strjoin("test -e saved_images/",
	ft_strjoin(ft_strjoin(IMG, ft_itoa(id), 'R'), ".png", 'L'), 'R');
	while (system(rt->ui->tmp) == 0)
	{
		free(rt->ui->tmp);
		rt->ui->tmp = ft_strjoin("test -e saved_images/", ft_strjoin(
		ft_strjoin(IMG, ft_itoa(++id), 'R'), ".png", 'L'), 'R');
	}
	free(rt->ui->tmp);
	rt->ui->n_save = ft_strjoin(ft_strjoin(IMG, ft_itoa(id), 'R'), ".bmp", 'L');
	save_to_png_part2(rt);
}

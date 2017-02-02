/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:48:30 by bsouchet          #+#    #+#             */
/*   Updated: 2017/01/26 13:47:30 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	print_scene_params(t_scene *s)
{
	write(1, "-- Scene Parameters ----------------------\n", 43);
	write(1, "\nScene Name    : ", 17);
	write(1, s->name, ft_strlen(s->name));
	write(1, "\nAmbient (AO)  : ", 17);
	ft_putdouble(s->ambient);
	write(1, "\nAnti-Aliasing : ", 17);
	ft_putint(s->aa);
	write(1, "\nMax-Reflexion : ", 17);
	ft_putint(s->m_ref);
	write(1, "\n", 1);
}

static void	print_camera(t_obj *c)
{
	write(1, "\nName          : ", 17);
	write(1, c->n, ft_strlen(c->n));
	write(1, "\nFocal         : ", 17);
	ft_putshort(c->fl);
	write(1, "\nPosition      : ", 17);
	ft_putdouble(c->pos.x);
	write(1, " , ", 3);
	ft_putdouble(c->pos.y);
	write(1, " , ", 3);
	ft_putdouble(c->pos.z);
	write(1, "\nRotation      : ", 17);
	ft_putdouble(c->rot.x);
	write(1, " , ", 3);
	ft_putdouble(c->rot.y);
	write(1, " , ", 3);
	ft_putdouble(c->rot.z);
	write(1, "\n", 1);
}

static void	print_light(t_obj *l)
{
	write(1, "\nName          : ", 17);
	write(1, l->n, ft_strlen(l->n));
	write(1, "\nVisibility    : ", 17);
	ft_putshort(l->v);
	write(1, "\nIntensity     : ", 17);
	ft_putfloat(l->i);
	write(1, "\nColor         : ", 17);
	ft_putdouble(l->rgb.x);
	write(1, " , ", 3);
	ft_putdouble(l->rgb.y);
	write(1, " , ", 3);
	ft_putdouble(l->rgb.z);
	write(1, "\nPosition      : ", 17);
	ft_putdouble(l->pos.x);
	write(1, " , ", 3);
	ft_putdouble(l->pos.y);
	write(1, " , ", 3);
	ft_putdouble(l->pos.z);
	write(1, "\n", 1);
}

static void	print_object(t_obj *o)
{
	write(1, "\nName          : ", 17);
	write(1, o->n, ft_strlen(o->n));
	write(1, "\nType          : ", 17);
	/*ft_putshort(o->t);*/
	printf("Not Available\n");
	write(1, "Material      : ", 16);
	ft_putshort(o->m);
	write(1, "\nVisibility    : ", 17);
	ft_putshort(o->v);
	write(1, "\nOpacity       : ", 17);
	ft_putdouble(o->op);
	write(1, "\nColor         : ", 17);
	ft_putdouble(o->rgb.x);
	write(1, " , ", 3);
	ft_putdouble(o->rgb.y);
	write(1, " , ", 3);
	ft_putdouble(o->rgb.z);
	write(1, "\nPosition      : ", 17);
	ft_putdouble(o->pos.x);
	write(1, " , ", 3);
	ft_putdouble(o->pos.y);
	write(1, " , ", 3);
	ft_putdouble(o->pos.z);
	write(1, "\nRotation      : ", 17);
	ft_putdouble(o->rot.x);
	write(1, " , ", 3);
	ft_putdouble(o->rot.y);
	write(1, " , ", 3);
	ft_putdouble(o->rot.z);
	write(1, "\n", 1);
}

static void	print_title(char c)
{
	if (c == 'C')
		write(1, "\n-- Camera(s) -----------------------------\n", 44);
	else if (c == 'L')
		write(1, "\n-- Light(s) ------------------------------\n", 44);
	else if (c == 'O')
		write(1, "\n-- Object(s) -----------------------------\n", 44);
}

void		print_verbose(t_rt *rt)
{
	t_obj	*list;

	list = rt->scn->o;
	print_scene_params(rt->scn);
	print_title('C');
	list = list->next;
	while (list->next != NULL && list->t == 'C')
	{
		print_camera(list);
		list = list->next;
	}
	print_title('L');
	list = list->next;
	while (list->next != NULL && list->t == 'L')
	{
		print_light(list);
		list = list->next;
	}
	print_title('O');
	list = list->next;
	while (list != NULL)
	{
		print_object(list);
		list = list->next;
	}
}

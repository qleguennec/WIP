/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:44:28 by bsouchet          #+#    #+#             */
/*   Updated: 2017/01/23 18:23:23 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Need sufficient malloc on each pthread #pthread_attr_getstack()
** Need also a pthread_mutex handling as rt->tab is shared between threads
*/

void		set_thread(t_thread *t, t_rt *rt, int *i, int *j, int *s)
{
	int		ret;

	t->arg.rt = rt;
	t->arg.scn = rt->scn;
	t->arg.i = i;
	t->arg.j = j;
	t->arg.tab = rt->tab;
	t->arg.s = s;
	if ((ret = pthread_attr_init(&t->attr)) != 0)
	{
		ft_dprintf(2, "RT error %d - pthread_attr_init failed\n", ret);
		exit(-1);
	}
	if ((ret = pthread_attr_setstack(&t->attr, &(rt->stack), STACK_SIZE)) != 0)
	{
		//ft_dprintf(2, "RT error %d - pthread_attr_setstack failed\n", ret);
		//exit(-1);
	}
	if ((ret = pthread_create(&t->thread, &t->attr, (void*)thread_render, \
		(void*)&t->arg)) != 0)
	{
		ft_dprintf(2, "RT error %d - pthread_create failed\n", ret);
		exit(-1);
	}
}

char		join_thread(t_thread *t)
{
	int		ret;

	if ((ret = pthread_join(t->thread, NULL)) != 0)
	{
		ft_dprintf(2, "RT error %d - pthread_join failed\n", ret);
		exit(-1);
	}
	return (1);
}

char		destroy_thread_attr(t_thread *t)
{
	int		ret;

	if ((ret = pthread_attr_destroy(&t->attr)) != 0)
	{
		ft_dprintf(2, "RT error %d - pthread_attr_destroy failed\n", ret);
		exit(-1);
	}
	return (1);
}

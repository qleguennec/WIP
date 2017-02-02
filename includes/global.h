/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 19:27:50 by bsouchet          #+#    #+#             */
/*   Updated: 2017/01/23 13:31:56 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GLOBAL_H
# define _GLOBAL_H

# define UCHAR			unsigned char
# define UINT			unsigned int
# define BOOL			int
# define TRUE			1
# define FALSE			0

# ifdef __linux__
#  define PAGE_SIZE		4096
# endif
# define STACK_SIZE	(1 * PAGE_SIZE)

# define ALIASING		100
# define NO_ALIASING	1
# define MAX_DEPTH		25
# define RT_SUBXY		60
# define MULTISAMP		2

# define MAX_FPS		25

# define HELP			-2
# define ERROR			-1

# define EV_EXIT		-1
# define EV_RESIZE		-2

# define OBJ_PLANE_XY	0x1
# define OBJ_PLANE_YZ	0x2
# define OBJ_PLANE_XZ	0x4
# define OBJ_SPHERE		0x5
# define OBJ_CUBE		0x10
# define OBJ_PYRAMID	0x20
# define OBJ_CYLINDER	0x40
# define OBJ_SKYBOX		0x50

# define SKYBX_NONE		0x0
# define SKYBX_GRADIENT	0x1

# define NULL_PARAM		0.0
# define NULL_RECT		(SDL_Rect){0, 0, 0, 0}

# define MAT_LAMBERT	0x1
# define MAT_METAL		0x2
# define MAT_DIELECT	0x4
# define MAT_DIFF_LIGHT	0x8

#endif

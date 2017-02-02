/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 20:20:12 by bsouchet          #+#    #+#             */
/*   Updated: 2017/01/07 22:01:32 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H

# include <math.h>
# include <stdlib.h>

/*
** -----------------------------------------------------------------------------
** ------------------------------- Structures ----------------------------------
** -----------------------------------------------------------------------------
*/

typedef struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef struct	s_vec4
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_vec4;

/*
** -----------------------------------------------------------------------------
** ------------------------------- Functions -----------------------------------
** -----------------------------------------------------------------------------
*/

/*
** --------------------------------- vec3 ---------------------------------------
*/

t_vec3			v3(double const x, double const y, double const z);
t_vec3			*v3_new_vec(double const x, double const y, double const z);
t_vec3			*v3_copy_vec(t_vec3 const v);
void			v3_set(t_vec3 *v, double const x, double const y,
				double const z);
void			v3_free(t_vec3 *v);

double			v3_access(t_vec3 *v, int i);

t_vec3			*v3_add_vec(t_vec3 const v1, t_vec3 const v2);
t_vec3			*v3_sub_vec(t_vec3 const v1, t_vec3 const v2);
t_vec3			*v3_cross_vec(t_vec3 const v1, t_vec3 const v2);
t_vec3			*v3_multiply_vec(t_vec3 const v1, t_vec3 const v2);
t_vec3			*v3_scale_vec(t_vec3 const v, double const c);
t_vec3			*v3_div_vec(t_vec3 const v, double const c);

void			v3_normalize(t_vec3 *v);
void			v3_negative(t_vec3 *v);

double			v3_dot_double(t_vec3 const v1, t_vec3 const v2);
double			v3_magnitude_double(t_vec3 const v);
double			v3_lenght_double(t_vec3 const v);

t_vec3			*v3_unit_vec(t_vec3 const v);

/*
** --------------------------------- vec3 ---------------------------------------
*/

t_vec4			v4(double const x, double const y, double const z,
				double const w);
t_vec4			*v4_new_vec(double const x, double const y, double const z,
				double const w);
t_vec4			*v4_copy_vec(t_vec4 const v);
void			v4_set(t_vec4 *v, t_vec3 const xyz, double const w);
void			v4_free(t_vec4 *v);

double			v4_access(t_vec4 *v, int i);

t_vec4			*v4_add_vec(t_vec4 const v1, t_vec4 const v2);
t_vec4			*v4_sub_vec(t_vec4 const v1, t_vec4 const v2);
t_vec4			*v4_cross_vec(t_vec4 const v1, t_vec4 const v2);
t_vec4			*v4_multiply_vec(t_vec4 const v1, t_vec4 const v2);
t_vec4			*v4_scale_vec(t_vec4 const v, double const c);
t_vec4			*v4_div_vec(t_vec4 const v, double const c);

void			v4_normalize(t_vec4 *v);
void			v4_negative(t_vec4 *v);

double			v4_dot_double(t_vec4 const v1, t_vec4 const v2);
double			v4_magnitude_double(t_vec4 const v);
double			v4_lenght_double(t_vec4 const v);

t_vec4			*v4_unit_vec(t_vec4 const v);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 20:07:57 by bsouchet          #+#    #+#             */
/*   Updated: 2017/02/02 19:13:57 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3		*v3_add_vec(t_vec3 const v1, t_vec3 const v2)
{
	return (v3_new_vec(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_vec3		*v3_sub_vec(t_vec3 const v1, t_vec3 const v2)
{
	return (v3_new_vec(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

t_vec3		*v3_cross_vec(t_vec3 const v1, t_vec3 const v2)
{
	return (v3_new_vec(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z,
	v1.x * v2.y - v1.y * v2.x));
}

t_vec3		*v3_multiply_vec(t_vec3 const v1, t_vec3 const v2)
{
	return (v3_new_vec(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z));
}

t_vec3		*v3_scale_vec(t_vec3 const v, double const c)
{
	return (v3_new_vec(v.x * c, v.y * c, v.z * c));
}

t_vec3		*v3_div_vec(t_vec3 const v, double const c)
{
	return (v3_new_vec(v.x / c, v.y / c, v.z / c));
}

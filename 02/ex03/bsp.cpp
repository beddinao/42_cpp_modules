/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:40:57 by beddinao          #+#    #+#             */
/*   Updated: 2024/01/09 17:47:43 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Fixed.hpp"
#include "Point.hpp"

// // / Area = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2 
Fixed	area (Point const a, Point const b, Point const c)
{
	Fixed		res(((a.getfx() * (b.getfy() - c.getfy())) +
					(b.getfx() * (c.getfy() - a.getfy())) +
					(c.getfx() * (a.getfy() - b.getfy())) ) / 2.0f);
	Fixed		zero(0);

	if (res < zero)
		res = Fixed(res * Fixed(-1));
	return (res);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed		zero(0);
	Fixed		area_( area(a, b, c) );
	Fixed		sub_area_1( area(point, b, c) );
	Fixed		sub_area_2( area(a, point, c) );
	Fixed		sub_area_3( area(a, b, point) );
	Fixed		sub_areas_sum(sub_area_1 + sub_area_2 + sub_area_3);

	if (sub_area_1 == zero || sub_area_2 == zero || sub_area_3 == zero)
		return (0);
	return (area_ == sub_areas_sum);
}

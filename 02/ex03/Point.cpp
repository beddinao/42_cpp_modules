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
#include "Point.hpp"

Point::Point()
	: x(0), y(0) {};

Point::~Point() {}

Point::Point( const float x, const float y)
	: x(x), y(y) {}

Point::Point( const Point &_p )
{
	*this = _p;
}

void		Point::operator = ( const Point &_p )
{
	Fixed			*f_ptr = (Fixed *)(&this->x);
	*f_ptr = Fixed(_p.getfx().toFloat());
	f_ptr = (Fixed *)(&this->y);
	*f_ptr = Fixed(_p.getfy().toFloat());
}

const	Fixed	&Point::getfx( void ) const
{
	return (x);
}

const	Fixed	&Point::getfy( void ) const
{
	return (y);
}

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
#include <iostream>
#include "Fixed.hpp"

class		Point
{
	Fixed	const	x;
	Fixed	const	y;
	public:
		Point();
		Point( const float x, const float y );
		Point( const Point & );
		void	operator = ( const Point & );
		const Fixed	&getfx( void ) const;
		const Fixed	&getfy( void ) const;
		~Point();
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

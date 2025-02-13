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
#include <cmath>

Fixed::Fixed()
	: frac_bits(8)
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &_copy )
	: frac_bits(8)
{
	std::cout << "copy constructor called" << std::endl;
	*this = _copy;
}

void	Fixed::operator = ( const Fixed &_copy )
{
	std::cout << "Copy assignment operator called" << std::endl;
	value = _copy.value;
}

void	Fixed::setRawBits(int const raw)
{
	value = raw;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}
//////////////////
///
Fixed::Fixed(int const integer)
	: frac_bits(8)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(integer << frac_bits);
}
Fixed::Fixed(float const f_point_number)
	: frac_bits(8)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(f_point_number * ft_power(2, frac_bits));
}
//////////////////
///
float	Fixed::toFloat( void ) const
{
	return (value / ft_power(2, frac_bits));
}
int	Fixed::toInt(void ) const
{
	return (value >> frac_bits);
}
/////////////////
///
int	Fixed::operator << (int	integer)
{
	return (integer);
}

std::ostream	&operator << (std::ostream &c, const Fixed &fix)
{
	c << fix.toFloat();
	return (c);
}

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

/// // // /			Constructors :

Fixed::Fixed(): value(0), frac_bits(8) {};
Fixed::~Fixed() {}
Fixed::Fixed( const Fixed &_copy )
	: frac_bits(8)
{
	*this = _copy;
}
Fixed::Fixed(int const integer)
	: frac_bits(8)
{
	setRawBits(integer << frac_bits);
}
Fixed::Fixed(float const f_point_number)
	: frac_bits(8)
{
	this->value = roundf(f_point_number * ft_power(2, frac_bits));
}

//// /// ///// 		Special member Functions :

void	Fixed::setRawBits(int const raw)
{
	value = raw;
}

int	Fixed::getRawBits( void ) const
{
	return (value);
}

float	Fixed::toFloat( void ) const
{
	return (value / ft_power(2, frac_bits));
}
int	Fixed::toInt(void ) const
{
	return (value >> frac_bits);
}

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
const	Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const	Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

//// // ///// ///		Operators :

void	Fixed::operator = ( const Fixed &_copy )
{
	value = _copy.value;
}
/////////////////
///		for compatiblity:
int	Fixed::operator << (int	integer)
{
	return (integer);
}
////////////////	
///		global overloading operators:
///
///
std::ostream	&operator << (std::ostream &c, const Fixed &fix)
{
	c << fix.toFloat();
	return (c);
}
////////////////
///		comparison operators
///

bool	Fixed::operator > (Fixed const &fix) const
{
	return (getRawBits() > fix.getRawBits());
}

bool	Fixed::operator < (Fixed const &fix) const
{
	return (getRawBits() < fix.getRawBits());
}

bool	Fixed::operator >= (Fixed const &fix) const
{
	return (getRawBits() >= fix.getRawBits());
}

bool	Fixed::operator <= (Fixed const &fix) const
{
	return (getRawBits() <= fix.getRawBits());
}

bool	Fixed::operator	== (Fixed const &fix) const
{
	return ((value / ft_power(2, frac_bits)) == (fix.getRawBits() / ft_power(2, frac_bits)));
}

bool	Fixed::operator	!= (Fixed const &fix) const
{
	return ((value / ft_power(2, frac_bits)) != (fix.getRawBits() / ft_power(2, frac_bits)));
}
/////////////////
///		arithmetic operators
///
Fixed	Fixed::operator + (Fixed const &fix) const
{
	Fixed			temp;

	temp.setRawBits( (getRawBits()) + (fix.getRawBits()) );
	return (temp);
}

Fixed	Fixed::operator - (Fixed const &fix) const
{
	Fixed			temp;

	temp.setRawBits( getRawBits() - fix.getRawBits() );
	return (temp);
}

Fixed	Fixed::operator * (Fixed const &fix) const
{
	Fixed			temp;

	temp.setRawBits((getRawBits() * fix.getRawBits()) / ft_power(2, frac_bits));
	return (temp);
}

Fixed	Fixed::operator / (Fixed const &fix) const
{
	Fixed			temp((float)
				(
					(value / ft_power(2, frac_bits)) /
					(fix.getRawBits() / ft_power(2, frac_bits))
				));

	return (temp);
}

////////////////
///		post/pre increment
Fixed&	Fixed::operator ++ ( void )
{
	this->value = roundf(toFloat() * ft_power(2, frac_bits)) + 1;
	return (*this);
}

Fixed&	Fixed::operator -- ( void )
{
	this->value = roundf(toFloat() * ft_power(2, frac_bits)) - 1;
	return (*this);
}

Fixed	Fixed::operator ++ ( int p_h )
{
	(void)p_h;
	Fixed	tmp(*this);
	operator ++ ();
	return tmp;
}

Fixed	Fixed::operator -- ( int p_h )
{
	(void)p_h;
	Fixed	tmp(*this);
	operator -- ();
	return tmp;
}

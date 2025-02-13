/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:40:57 by beddinao          #+#    #+#             */
/*   Updated: 2024/01/09 17:47:43 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Fixed.hpp"

Fixed::Fixed()
	: frac_bits(8)
{
	std::cout << "default constructor called" << std::endl;
	value = 0;
}

Fixed::~Fixed()
{
	std::cout << "destructor called" << std::endl;
}

Fixed::Fixed(Fixed &_copy)
	: frac_bits(8)
{
	std::cout << "copy constructor called" << std::endl;
	*this = _copy;
}

void	Fixed::operator = (Fixed &_copy)
{
	(void)frac_bits;
	std::cout << "copy assignment operator called" << std::endl;
	value = _copy.getRawBits();
}

void	Fixed::setRawBits(int const raw)
{
	value = raw;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

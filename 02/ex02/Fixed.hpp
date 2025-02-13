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
#pragma 	once
#include <iostream>

class		Fixed
{
	private:
		int			value;
		const	int		frac_bits;
	public:
		Fixed();
		Fixed( const Fixed &_copy );
		void operator = ( const Fixed &_copy );
		~Fixed();
		Fixed( const int integer );
		Fixed( const float f_point_number);
		//>
		void	setRawBits( int const raw );
		int		getRawBits() const;
		float	toFloat() const;
		int		toInt() const;
		//>
		static	Fixed	&min(Fixed &a, Fixed &b);
		static	Fixed	&max(Fixed &a, Fixed &b);
		static	const	Fixed	&min(const Fixed &a, const Fixed &b);
		static	const	Fixed	&max(const Fixed &a, const Fixed &b);
		//>
		int	operator << ( int integer );
		//>
		bool	operator >  (Fixed const &fix) const;
		bool	operator <  (Fixed const &fix) const;
		bool	operator >= (Fixed const &fix) const;
		bool	operator <= (Fixed const &fix) const;
		bool	operator == (Fixed const &fix) const;
		bool	operator != (Fixed const &fix) const;
		//>
		Fixed	operator + (Fixed const &fix) const;
		Fixed	operator - (Fixed const &fix) const;
		Fixed	operator * (Fixed const &fix) const;
		Fixed	operator / (Fixed const &fix) const;
		//>
		Fixed	&operator ++ ();
		Fixed	&operator -- ();
		Fixed	operator ++ ( int p_h );
		Fixed	operator -- ( int p_h );
};

std::ostream	&operator << ( std::ostream &c, const Fixed &fix );
float			ft_power(float nb, float number);

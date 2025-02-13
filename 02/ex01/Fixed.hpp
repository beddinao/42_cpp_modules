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
		//>
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		//>
		Fixed( const int integer );
		Fixed( const float f_point_number);
		//>
		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		operator << ( int integer );
};

std::ostream	&operator << ( std::ostream &c, const Fixed &fix );
float				ft_power(float nb, float power);

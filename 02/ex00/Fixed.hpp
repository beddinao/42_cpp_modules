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
	int			value;
	const int		frac_bits;
	public:
		Fixed();
		Fixed( Fixed &fix );
		void operator = ( Fixed &fix );
		~Fixed();
		//>
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

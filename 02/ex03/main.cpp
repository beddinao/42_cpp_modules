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

int main()
{
	Point		const		a(0, 0);
	Point		const		b(10, 30);
	Point		const		c(20, 0);


	Point		const		point_1(10, 15);
	Point		const		point_2(20, 15);
	Point		const		point_3(10, 30);
	Point		const		point_4(0, 0);
	/*
		A(0, 0) ----------- C (20, 0)
		P4 		\         /
				 \   P1  / P2
				  \     /
				   \   /
				   	\ /
					B(10, 30)
					P3
	 */
	std::cout << "P1" << (bsp(a, b, c, point_1) ? " " : " not ") << "inside\n";
	std::cout << "P2" << (bsp(a, b, c, point_2) ? " " : " not ") << "inside\n";
	std::cout << "P3" << (bsp(a, b, c, point_3) ? " " : " not ") << "inside\n";
	std::cout << "P4" << (bsp(a, b, c, point_4) ? " " : " not ") << "inside\n";
}

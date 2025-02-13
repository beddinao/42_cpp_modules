#pragma once
#include <iostream>
#include <vector>


template		<typename	T, typename A >
int		easyfind( T v, A a )
{
	typename T::iterator	i = find( v.begin(), v.end(), a );

	if (i != v.end())
		return (i - v.begin());
	return (-1);
}

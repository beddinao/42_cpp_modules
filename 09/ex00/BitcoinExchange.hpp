#pragma once
#include <iostream>
#include <fstream>
#include <list>			/*	LIST	*/
#include <map>
#define	DATABASE	"data.csv"
typedef	long long		u_lame;

void		calculate_amount(std::list<std::string>, std::map<u_lame, float>);
void		basics_check(std::string);
u_lame		get_n(std::string);

template		<typename T>
T		getLI(std::list<T>	&L, int index)
{
	typename std::list<T>::iterator	i = L.begin();
	for (int j = 0; i != L.end() && j < index; ++i, j++);
	return		(*i);
}

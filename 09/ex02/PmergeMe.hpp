#pragma once
#include <iostream>
#include <vector>			/*	VECTOR	*/
#include <deque>			/*	DEQUE	*/
#include <ctime>

typedef		long long	u_lame;

bool		basic_check(char **);
double		time_diff(clock_t);

template		<typename T>
bool		is_sorted(T d)
{
	typename	T::iterator	i = d.begin();
	for (; i != d.end() - 1; ++i)
		if (*i > *(i + 1))	return	0;
	return	1;
}

template		<typename	X>
void		insertion_sort(X &d)
{
	for (typename X::iterator i = d.begin(); i != d.end(); ++i)
		for (typename X::iterator j = i + 1; j != d.end(); ++j)
			if (*j < *i) {
				u_lame t = *i;
				*i = *j;
				*j = t;
			}
}

template		<typename X>
void	merge_insert_sort(X &d)
{
	if (is_sorted(d)) return ;
	X	d1( d.begin(), d.begin() + (d.size() / 2));
	X	d2( d.begin() + (d.size() / 2), d.end());
	d.clear();
	if (d1.size() > 3)	merge_insert_sort(d1);
	else		insertion_sort(d1);
	if (d2.size() > 3)	merge_insert_sort(d2);
	else		insertion_sort(d2);
	for (size_t n=0,i=0,j=0; n < (d1.size() + d2.size()); n++)
	{
		if (i < d1.size() && (j >= d2.size() || d1[i] < d2[j]))
			d.push_back( d1[i++] );
		else if (j < d2.size())	d.push_back( d2[j++] );
	}
}

template		<typename X>
void		printd(X d, std::string s)
{
	typename	X::iterator	i = d.begin();
	std::cout << s;
	for(; i != d.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
}

template		<typename	T>
void		fill(T &V, char **argv)
{
	for (int i = 1; argv[i]; i++)
		V.push_back( atol(argv[i]) );
}


template		<typename T>
void		execute(T& C, int con, std::string c_name)
{
	if (con)	printd(C, "Before:  ");
	clock_t		t_begin = clock();
	merge_insert_sort(C);
	double	d_time = time_diff(t_begin);
	if (con)	printd(C, "After:   ");
	std::cout << "Time to proccess a range of " << C.size()
		<< " elements with std::" << c_name << ": "
		<< d_time << " ms" << std::endl;
}

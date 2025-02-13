#pragma once
#include <iostream>
#include <vector>
#include <stack>


template		<typename T>
class		MutantStack: public	std::stack<T>
{
	public:
		typedef	typename	std::deque<T>::iterator		iterator;
		typedef	typename	std::deque<T>::const_iterator		const_iterator;

		iterator		begin() { return	this->c.begin(); }
		iterator		end() { return	this->c.end(); }
		const_iterator	begin() const { return	this->c.begin(); }
		const_iterator	end() const { return	this->c.end(); }

		MutantStack() {}
		~MutantStack() {}
		MutantStack( const MutantStack &M ) { *this = M; }
		MutantStack	&operator = ( const MutantStack &M ) { this->c = M.c; return (*this); }
};


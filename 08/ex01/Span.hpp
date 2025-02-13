#pragma once
#include <iostream>
#include <vector>
	
class		Span
{
	std::vector<int>::iterator	i;
	std::vector<int>::iterator	index;
	std::vector<int>		nums;
	size_t			N[2];
	public:
		~Span();
		Span( unsigned int );
		Span( const Span & );
		Span	&operator = ( const Span & );
		class	invalidOperation: public std::exception
		{
			const	char* what() const throw();
		};
		//
		void	addNumber( int );
		size_t	shortestSpan( void );
		size_t	longestSpan( void );
		void	addRange( std::vector<int>& );
		//
		void	print( void );
};

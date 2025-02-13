#include "Span.hpp"

Span::~Span() { }

const	char*	Span::invalidOperation::what() const throw()
{
	return "invalid operation on the Span class";
}

Span::Span( unsigned int n )
{
	if (n >= INT_MAX)
		throw	invalidOperation();
	N[0] = 0;
	N[1] = n;
}

Span::Span( const Span &S )
{
	*this = S;
}

Span	&Span::operator = ( const Span &S )
{
	nums = S.nums;
	N[0] = S.N[0];
	N[1] = S.N[1];
	return (*this);
}

//>

void	Span::addNumber( int n )
{
	if (N[0] >= N[1])
		throw	invalidOperation();
	nums.push_back(n);
	N[0] += 1;
}

size_t	Span::shortestSpan( void )
{
	int		res  = (int)longestSpan();

	for ( index = nums.begin(); index != nums.end(); ++index )
		for ( i = nums.begin(); i != nums.end(); ++i )
		{
			int	a = abs(*index - *i);
			if (i != index && a < res)
				res = a;
		}
	return ((size_t)res);
}

size_t	Span::longestSpan( void )
{
	if (N[0] < 2)
		throw	invalidOperation();

	int	small = *(min_element(nums.begin(), nums.end()));
	int	big = *(max_element(nums.begin(), nums.end()));

	return ((size_t)abs(big - small));
}

void	Span::addRange(std::vector<int>	&V)
{
	if ((N[0] + V.size()) > N[1])
		throw	invalidOperation();
	nums.insert(nums.begin() + N[0], V.begin(), V.end());
	N[0] += V.size();
}

void	Span::print( void )
{
	int		a = 0;
	for (index = nums.begin(); index != nums.end(); ++index, a++)
		std::cout << a << ": " << *index << std::endl;
}

#pragma once
#include <iostream>

template	<typename T>
class		Array
{
	T		*arr;
	int		length;
	public:
		Array(): length(-1) {};
		Array( unsigned int n )
			: length(n)
		{
			if (n >= INT_MAX)
				throw InvalidIndx();
			arr = new T[n];
		}
		Array( const Array &A ) { *this = A; }
		~Array() { if (length > 0) delete [] arr; }
		
		////		[] operator overlaod
		//
		T&		operator [] ( int i ) const
		{
			if (length < 0 || i < 0 || i >= length)
				throw InvalidIndx();
			return arr[i];
		}
		
		////		= operator overload
		//
		Array		&operator = ( const Array &A )
		{
			if (this != &A )
			{
				length = A.size();
				arr = new T[length];
				//
				for (int i = 0; i < length; i++)
					arr[i] = A[i];
			}
			return *this;
		}

		int		size() const { return length; }

		////		exception
		//
		class		InvalidIndx: public std::exception
		{
			const char* what() const throw()
			{
				return "invalid operation on the Array class";
			}
		};
};

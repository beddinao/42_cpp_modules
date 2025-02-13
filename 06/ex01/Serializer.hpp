#pragma once
#include <iostream>
#include "Data.hpp"

class			Serializer
{
	public:
		Serializer();
		Serializer( const Serializer & );
		Serializer	&operator = ( const Serializer & );
		virtual	~Serializer() =0;
		//>
		static uintptr_t		serialize( Data * );
		static Data*		deserialize( uintptr_t );
};

#include "Serializer.hpp"

Serializer::Serializer() {};
Serializer::~Serializer() {};

Serializer::Serializer( const Serializer &S )
{
	*this = S;
}

Serializer	&Serializer::operator = ( const Serializer &S )
{
	(void)S;
	return (*this);
}

uintptr_t		Serializer::serialize( Data *ptr )
{
	ptr->addr = reinterpret_cast<uintptr_t*>(ptr);
	return (*ptr->addr);
}

Data*		Serializer::deserialize( uintptr_t raw )
{
	return (reinterpret_cast<Data*>(raw));
}

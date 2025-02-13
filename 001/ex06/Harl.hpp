#include <iostream>
#include <cstring>

class		Harl
{
	void		debug( void );
	void		info( void );
	void		warning( void );
	void		error( void );
	public:
		void	complain( std::string	level, int min_level );
		Harl( void );
		~Harl( void );
};

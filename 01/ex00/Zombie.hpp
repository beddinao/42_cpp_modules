#include <iostream>

class	Zombie{
	private:
		std::string				name;
	public:
		void		announce( void );
		void		setName(std::string new_name);
		Zombie( void );
		~Zombie( void );
};

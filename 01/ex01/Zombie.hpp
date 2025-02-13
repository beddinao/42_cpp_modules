#include <iostream>

class	Zombie{
	private:
		std::string				name;
	public:
		void		announce( void );
		void		setName(std::string new_name);
		Zombie();
		~Zombie( void );
};

Zombie			*zombieHorde(int N, std::string name);

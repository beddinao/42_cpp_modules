#include <iostream>
#include <string>
#include <cstring>
#include <cctype>


class	Contact{
	private:
		int				id;
		std::string			info[5];
	public:
		std::string			keys_[5];
		Contact();
		void	add_(std::string str, int index);
		void	display_with_all( void );
		void	display_( void );
		void	reset_( void );
		void	set_id( int new_id );
		int		get_id( void );
};

int		b_strlen(std::string str);
std::string	b_substr(std::string str, int start, int end);
std::string	b_to_string(size_t number);

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook{
	private:
		int			current;
		int			prev;
		Contact			_contacts[8];
	public:
		PhoneBook(int current, int prev);
		void	add_contact();
		void	search_contact();
		void	display_();
};

std::string	b_read_str(std::string out, int is_num);
std::string	b_to_string(size_t number);
int		b_stoi(std::string str);

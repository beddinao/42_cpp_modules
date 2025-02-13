#include "Contact.hpp"

Contact::Contact()
{
	this->keys_[0] = "First Name";
	this->keys_[1] = "Last Name";
	this->keys_[2] = "Nick Name";
	this->keys_[3] = "Phone number";
	this->keys_[4] = "Darkest secret";
}

void	Contact::add_(std::string str, int index)
{
	info[index] = str;
}

void	Contact::set_id( int new_id )
{
	id = new_id;
}

int	Contact::get_id( void )
{
	return (id);
}

void	Contact::display_with_all( void )
{
	int				a = 0;
	std::string			temp_str;

	temp_str = "    " + b_to_string(get_id()) + "     |";
	while (a < 3)
	{
		if (b_strlen(info[a]) > 10)
			temp_str += b_substr(info[a], 0, 10);
		else if (b_strlen(info[a]) < 10)
		{
			int	b = 10 - b_strlen(info[a]), c = 0;
			while (c <= b)
			{
				if (c == b / 2)
					temp_str += info[a];
				else
					temp_str += " ";
				c++;
			}
		}
		temp_str += "|";
		a++;
	}
	std::cout << temp_str << std::endl;
}

void	Contact::reset_( void )
{
	int 			a = 0;

	while (a < 5)
		info[a++] = "";
}

void	Contact::display_( void )
{
	int			a = 0;

	while (a < 5)
	{
		std::cout << keys_[a] << ": " << info[a] << std::endl;
		a++;
	}
}

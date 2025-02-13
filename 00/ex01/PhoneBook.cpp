#include "PhoneBook.hpp"

PhoneBook::PhoneBook(int current, int prev):
	current(current), prev(prev) {}

void	PhoneBook::add_contact()
{
	int			a = 0;
	if (prev)
		_contacts[current].reset_();
	_contacts[current].set_id(current);
	while (a < 5)
	{
		_contacts[current].add_(b_read_str(_contacts[current].keys_[a] + ": ", 0), a);
		a++;
	}
	current += 1;
	if (current > 7)
	{
		prev += 1;
		current = 0;
	}
}

void	PhoneBook::display_()
{
	int					a = 0;
	int					b;
	int					c;

	std::cout << std::endl
		<< " index    |First Name|Last Name |Nick Name |"
		<< std::endl;
	c = 11;
	b = 11;
	std::cout << std::setw(11) << std::setfill('-');
	while (b < 45)
	{
		if (b != 44 && b % c)
			std::cout << "-";
		else if (c += 11)
			std::cout << "|";
		b++;
	}
	std::cout << std::endl;
	while ((a < current && !prev) || (a < 8 && prev))
	{
		_contacts[a++].display_with_all();
		b = -1;
		while (++b < 44)
			std::cout << "-";
		std::cout << std::endl;
	}
}

void	PhoneBook::search_contact()
{
	long					num;
	int					a = 0;

	if (prev || current)
		display_();
	while (1)
	{
		num = b_stoi(b_read_str("Which Contact index: ", 1));
		if (num < 0 || num > 7
			|| (!prev && num >= current))
		{
			std::cout << "\terr: invalid index (" << num << ") try: ";
			if (!current && !prev)
				std::cout << "adding contact first";
			else if (!prev)
				std::cout << 0 << " -> " << current - 1;
			else
				std::cout << "0 -> 7";
			std::cout << std::endl;
			break ;
		}
		else
			_contacts[num].display_();
	}
}

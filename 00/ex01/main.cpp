#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include "PhoneBook.hpp"

int	b_strlen(std::string str)
{
	int			a = 0;

	while (str[a])
		a++;
	return (a);
}

int		b_stoi(std::string str)
{
	size_t			res = 0, a = 0;

	while (str[a])
		res = (res * 10) + (str[a++] - 48);
	return ((int)res);
}

std::string	b_substr(std::string str, int start, int end)
{
	char			new_str[end + 1];
	(void)start;
	strncpy(new_str, str.c_str(), end);
	new_str[end - 1] = '.';
	new_str[end] = '\0';
	return ((new_str));
}

std::string	b_to_string(size_t number)
{
	std::string			res;

	if (!number)
		res = "0";
	while (number)
	{
		res += (number % 10) + 48;
		number /= 10;
	}
	return (res);
}

std::string	b_read_str(std::string out, int is_num)
{
	std::string				line;
	while (1)
	{
		std::cout << out;
		std::getline(std::cin, line);
		if (!std::cin)
			exit(0);
		if (line[0] && line.length() > 0)
		{
			int	is_valid_num = 1, a = 0;
			while (a < line.length())
				if (!isdigit(line[a++]))
					is_valid_num = 0;
			if (is_num && is_valid_num
				|| !is_num)
				return (line);
			else
				std::cout
				<< "\terr: only numeric input in here" << std::endl;
		}
	}
}

int	check_command(std::string cmd)
{
	if (!cmd.compare("ADD"))
		return (1);
	else if (!cmd.compare("SEARCH"))
		return (2);
	else if (!cmd.compare("EXIT"))
		return (-1);
	return (0);
}

void	execute_cmd(PhoneBook *p_Book, int mode)
{
	if (mode == 1)
		p_Book->add_contact();
	else if (mode)
		p_Book->search_contact();
}

int main()
{
	std::string				cmd;
	PhoneBook				p_Book(0, 0);
	int					mode = 0;

	while (mode >= 0)
	{
		std::cout << "> ";
		std::getline(std::cin, cmd);
		if (!std::cin)
			break ;
		if ((mode = check_command(cmd)) > 0)
			execute_cmd(&p_Book, mode);
		else if (!mode)
			std::cout << "Usage: ADD || SEARCH || EXIT" << std::endl;
	}
}

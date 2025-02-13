#include	"BitcoinExchange.hpp"

void	exec_line(std::string line, std::map<u_lame, float> map)
{
	std::list<std::string>		input;
	try { basics_check(line); }
	catch ( int a )
	{
		std::cout << "Error: ";
		if (!a)		std::cout << "bad input => " << line;
		else if (a == 1)	std::cout << "not a valid date => " 
				<< line.substr(0, line.find("|"));
		else if (a == 2)	std::cout << "not a positive number";
		else if (a == 3)	std::cout << "too large number";
		else if (a == 4)	std::cout << "you got some empty stuff (\" \")";
		else		std::cout << "can't look up the database"
				<< " with this \"" << line << "\"";
		std::cout << std::endl;
		return ;
	}
	input.push_back(line.substr(0, line.find("|")));
	input.push_back(line.substr(line.find("|") +1));
	calculate_amount(input, map);
}

void		do_database(std::map<u_lame, float> &map)
{
	std::string		line_buf;
	std::fstream		database;
	database.open(DATABASE, std::ios::in);
	if (!database) {
		std::cout << "Error: can\'t open database: "
			<< DATABASE << std::endl;
		exit(1);
	}
	while (true)
	{
		std::getline(database, line_buf);
		if (!database || database.eof()) break;
		else if (line_buf == "date,exchange_rate") continue;
		map[ get_n(line_buf.substr(0, line_buf.find(","))) ] = atof(line_buf.substr(line_buf.find(",") + 1).c_str());
	}
	database.close();
}

int		main(int	c, char	**args)
{
	std::fstream			input;
	std::string			line_buf;
	std::map<u_lame, float>		map;
	int				h_tries=0;
	if (c == 2)
	{
		do_database(map);
		input.open(args[1], std::ios::in);
		if (!input)
		{
			std::cout << "Error: could not open file." << std::endl;
			return	(1);
		}
		while (std::getline(input, line_buf))
		{
			if (!h_tries && line_buf == "date | value")
			{
				h_tries = 1; continue;
			}
			exec_line(line_buf, map);
		}
		input.close();
		return	(0);
	}
	return	(1);
}

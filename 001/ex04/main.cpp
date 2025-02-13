#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

std::string	add_strs(char *s1, const char *s2)
{
	std::string		s_1 = s1;
	std::string		s_2 = s2;
	return (s_1 + s_2);
}

std::string	qk_covr(char *s)
{
	std::string				str = s;
	return (str);
}

int		sizeof_str(std::string str, char end)
{
	int					a = 0;
	while (str[a] && str[a] != end)
		a++;
	return (a);
}

std::string			is_there
	(std::string haystack, std::string needle, std::string new_str, std::string end, int a)
{
	while (a < sizeof_str(haystack, '\n') && haystack[a] != end[0])
	{
		if (haystack[a] == needle[0])
		{
			int	b = 0, a_2 = a;
			while (true)
			{
				if ((!needle[b] || needle[b] == end[1])
					&& haystack[a_2 - 1] == needle[b - 1])
					return (is_there(
								haystack.substr(0, a)
									+ new_str
									+ haystack.substr(a_2, sizeof_str(haystack, '\n')),
								needle,
								new_str,
								end,
								a + sizeof_str(new_str, '\0')
							));
				else if ((!needle[b] || needle[b] == end[1])
						|| (!haystack[a_2] || haystack[a_2] == end[0])
						|| haystack[a_2] != needle[b])
					break ;
				b++;
				a_2++;
			}
		}
		a++;
	}
	return (haystack);
}

int		main(int argc, char **argv)
{
	std::fstream				file_out;
	std::fstream				file_in;
	std::string					line_buf;

	if (argc == 4)
	{
		file_in.open(argv[1], std::ios::in);
		file_out.open(add_strs(argv[1], ".replace").data(), std::ios::out);
		if (!file_in || !file_out)
			return (std::cout << "error: invalid file" << std::endl, 0);
		while (std::getline(file_in, line_buf))
			file_out 
				<< is_there(line_buf,
						qk_covr(argv[2]),
						qk_covr(argv[3]), "\n\0", 0) 
				<< std::endl;
		file_out.close();
		file_in.close();
	}
	else
		std::cout << "Usage: ./copy <filename> <str_to_be_replaced> <str_to_replace>"
			<< std::endl;
}

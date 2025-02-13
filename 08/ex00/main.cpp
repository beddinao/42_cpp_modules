#include "easyfind.hpp"

int		main()
{
	std::cout << "test 1: sanity check: " << std::endl;
	std::vector<int>	nums(10);

	for (size_t	i = 0; i < nums.size(); i++)
		nums[ i ] = ('a' + i);
	//
	int		i = easyfind(nums, 'a' + 5);
	std::cout << static_cast<char>('a' + i) << std::endl;
	//
	////
	std::cout << "\ntest 2: sanity check: " << std::endl;
	std::vector<std::string>	strs(3);

	strs.push_back("str_1");
	strs.push_back("str_2");
	i		= easyfind(strs, "str_2");
	std::cout << "found in: " << i << std::endl;
	//
	////
	std::cout << "\ntest 3: error check " << std::endl;
	std::vector<int>		numm(2);
	numm.push_back(0);
	numm.push_back(1);
	i		= easyfind(numm, 3);
	std::cout << (i >= 0 ? "found": "not Found") << std::endl;
}

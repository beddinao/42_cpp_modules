#include "PmergeMe.hpp"

int		main(int	c, char	**argv)
{
	if (c > 2)
	{
		if (!basic_check(argv))
		{
			std::cout << "Error" << std::endl;
			return	1;
		}
		std::vector<u_lame>	V;
		fill(V, argv);
		execute(V, 1, "vector ");
		std::deque<u_lame>	D;
		fill(D, argv);
		execute(D, 0, "deque  ");
		return		0;
	}
	return	1;
}

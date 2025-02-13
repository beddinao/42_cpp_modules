#include "PmergeMe.hpp"

double		time_diff(clock_t	t_begin)
{
	return ((double)(clock() - t_begin));
}

bool		basic_check(char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
		for (int j=0; argv[i][j]; j++)
			if ((argv[i][j] > '9' || argv[i][j] < '0')
				&& (argv[i][j] != '+' || j))
				return	0;
	}
	return		1;
}

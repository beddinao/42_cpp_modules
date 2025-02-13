#include <iostream>

int	main(int args, char **argv)
{
	int							a;
	int							b;


	if (args > 1)
	{
		a = 1;
		while (a < args)
		{
			b = 0;
			while (argv[a][b])
			{
				if (argv[a][b] <= 'z' && argv[a][b] >= 'a')
					argv[a][b] -= 32;
				std::cout << argv[a][b++];
			}
			a++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << '\n';
}

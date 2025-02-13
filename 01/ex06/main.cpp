#include "Harl.hpp"

void		log_level(char *lev, int *min_level)
{
	int				log_level = 0;
	const char			*levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while (log_level < 4)
	{
		if (!strcmp(lev, levels[log_level]))
			break ;
		log_level += 1;
	}
	switch (log_level)
	{
		case 0:
			*min_level = 0;
			break ;
		case 1:
			*min_level = 1;
			break ;
		case 2:
			*min_level = 2;
			break ;
		case 3:
			*min_level = 3;
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problem ]" << std::endl;
			*min_level = 4;
	}
}

int		main(int argc, char **argv)
{
	int				min_level = 0;
	Harl				harl;

	if (argc > 1)
		log_level(argv[1], &min_level);

	harl.complain("DEBUG", min_level);
	harl.complain("INFO", min_level);
	harl.complain("WARNING", min_level);
	harl.complain("ERROR", min_level);
}

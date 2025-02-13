#include "Harl.hpp"

int		main()
{
	Harl		harl;

	/// / //		does nothing:
	///
	harl.complain("DEBUGING");

	// / ///		works:
	//
	harl.complain("INFO");
	harl.complain("ERROR");
}

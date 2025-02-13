#include "MutantStack.hpp"

void	leaks() { system("leaks stack"); }
int main()
{
	MutantStack<int>		mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl << std::endl;

	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
	return 0;
}

/*int main()
{
	atexit( leaks );
	MutantStack<int>		mstack;
	mstack.push(5);
	mstack.push(17);

	MutantStack<int>		mm = mstack;
	for (MutantStack<int>::iterator s = mm.begin(); s != mm.end(); ++s)
		std::cout << *s << std::endl;
}*/

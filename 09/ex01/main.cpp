#include "RPN.hpp"

void	_incr(std::string	input, int raw, size_t *i)
{
	while	(input[*i] == ' ')
		*i += 1;
	if (raw)
	{
		if (raw == 2 || (raw == 1 && IS_AO(input[*i])))
			*i += 1;
		while (raw == 1 && IS_NU(input[*i]))
			*i += 1;
	}
}

void	postfixNotationSyntax_check(std::string	input)
{
	u_lame			ops_count =0;
	u_lame			num_count =0;

	for (size_t i = 0; i < input.size();)
	{
		if (IS_SP(input[i]))	_incr(input, 0, &i);
		else if (IS_NU(input[i])
			|| (IS_AO(input[i]) && IS_NU(input[i+1])))
			num_count++, _incr(input, 1, &i);
		else if (IS_OP(input[i]))
		{
			if (num_count < 2)	throw	1;
			ops_count++, _incr(input, 2, &i);
		}
		else			throw	2;
	}
	if (ops_count < num_count - 1)	throw	3;
	if (ops_count > num_count - 1)	throw	4;
}

int	main(int	c, char	**args)
{
	if (c == 2)
	{
		try { postfixNotationSyntax_check(args[1]); }
		catch (int i)
		{
			switch (i)
			{
				case 1:	std::cout << "not a valid Postfix Notation"; break;
				case 3:	std::cout << "not enough Operations To Numbers"; break;
				case 4:	std::cout << "not enough Numbers To Operations"; break;
				default:	std::cout << "Error";
			}
			std::cout << std::endl;
			return (i);
		}
		std::stack<u_lame>	S;
		try { std::cout << RPN(S, args[1]) << std::endl; }
		catch (const char *message)
		{
			std::cout << "Error while processing notation: " << message
				<< std::endl;
			return	(1);
		}
		return (0);
	}
	return (1);
}

#include "RPN.hpp"

u_lame		Calculator(u_lame n1, u_lame n2, char	OP)
{
	switch	(OP)
	{
		case	'+':	return (n1 + n2);
		case	'-':	return (n1 - n2);
		case	'/':	return (n1 / n2);
		default:		return (n1 * n2);
	}
}

u_lame		S_pop(std::stack<u_lame> &S)
{
	if (!S.size())	throw	"not equal operands";
	u_lame	top_n = S.top();
	S.pop();
	return (top_n);
}

void	zero_exception(char OP, u_lame n)
{
	if (n || OP != '/')		return;
	throw "you CAN\'T DIVIDE BY zero";
}

std::string	&incr_(std::string &input, int raw)
{
	try {
		while (IS_SP(input[0]))
			input.erase(0, 1);
		if (raw)
		{
			if ((raw == 1 && IS_AO(input[0]))
				|| raw == 2)
				input.erase(0, 1);
			while (raw == 1 && IS_NU(input[0]))
				input.erase(0, 1);
			return incr_(input, 0);
		}
	}
	catch (const std::out_of_range &e){
		std::cout << "Error: fatal:\
			 not a valid string"
			 << input << std::endl;
		exit(1);
	}
	return (input);
}

u_lame		RPN(std::stack<u_lame> S, std::string input)
{
	incr_(input, 0);
	if (IS_NU(input[0])
		|| (IS_AO(input[0]) 
		&& input.size() > 1 && IS_NU(input[1])))
	{
		S.push(atol(input.c_str()));
		return RPN(S, incr_(input, 1));
	}
	else if (IS_OP(input[0]))
	{
		u_lame	n_1(S_pop(S));
		u_lame	n_2(S_pop(S));
		zero_exception(input[0], n_1);
		S.push(Calculator(n_2, n_1, input[0]));
		return RPN(S, incr_(input, 2));
	}
	else if (S.size() > 1)	throw "not valid notation";
	else	return S.top();
}

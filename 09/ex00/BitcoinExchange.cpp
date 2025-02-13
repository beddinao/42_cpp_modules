#include	"BitcoinExchange.hpp"

u_lame		get_n(std::string buff)
{
	u_lame	res = atol(buff.c_str());
	buff = buff.substr(buff.find("-") + 1);
	res = (res * 1000) + atol(buff.c_str());
	buff = buff.substr(buff.find("-") + 1);
	res = (res * 1000) + atol(buff.c_str());
	return	res;
}

void		calculate_amount(std::list<std::string> input, std::map<u_lame, float> map)
{
	u_lame	sp_n = get_n( getLI(input, 0) );
	std::map<u_lame, float>::iterator	exchange_rate = map.lower_bound( sp_n );
	while (exchange_rate->first > sp_n
		|| exchange_rate == map.end())	exchange_rate--;
	if (exchange_rate == map.begin())		exchange_rate++;
	std::cout << getLI(input, 0) << "=>" << getLI(input, 1) << " = "
		<< (atof(getLI(input, 1).c_str()) * exchange_rate->second) << std::endl;
}

int	is_sum_valid(char s)
{
	if ((s <= '9' && s >= '0') || s == ' ' || s == '.')
		return (1);
	return (0);
}

void	extra_op(std::string str, int con)
{
	int		sp_try[2] = {0};
	if (str.empty())	throw	4;
	if (con)
	{
		for (size_t i=0;i < str.size(); i++)
		{
			if (str[i] <= '9' && str[i] >= '0')
				sp_try[0] = 1;
			else if (str[i] == '.')
			{
				if (sp_try[1]) throw 5;
				sp_try[1] = 1;
			}
			else if (sp_try[0])	throw 5;
		}
		if (!sp_try[0]) throw 5;
	}
}

void	basics_check(std::string	input)
{
	int	month=0, day=0;
	if (input.empty())	throw	4;
	if (input.find("|") == input.npos
		|| input[4] != '-' || input[7] != '-') throw 0;
	std::string f_half = input.substr(0, input.find("|"));
	std::string s_half = input.substr(input.find("|") + 1);
	extra_op(f_half, 0),	extra_op(s_half, 1);
	if (atol(s_half.c_str()) < 0)	throw	2;
	else if (atol(s_half.c_str()) >= 1000) throw	3;
	for (size_t i = 0; i < f_half.size(); i++)
	{
		if (f_half[i] == '-' && (i == 4 || i == 7))
		{
			int time = atoi(f_half.substr(i+1).c_str());
			if ((i==4 && (time > 12||time<1))
				|| (i==7 && (time > 31||time<1))) throw 1;
			else if (i == 7 && time > 29 && time < 32) day=1;
			else if (i == 4 && time == 2)	month=1;
		}
		else if (!is_sum_valid(f_half[i])) throw 0;
	}
	for (size_t i = 0; i < s_half.size(); i++)
		if (!is_sum_valid(s_half[i])) throw 0;
	if (month && day)	throw	4;
}

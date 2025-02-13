#pragma	once
#include	<stack>		/*    STACK    */
#include	<iostream>

#define	IS_NU(C) (C <= '9' && C >= '0')
#define	IS_AO(C) (C == '-' || C == '+')
#define	IS_OP(C) (C == '/' || C == '*' \
		|| IS_AO(C))
#define	IS_SP(C) (C == ' ')

typedef	long long		u_lame;

u_lame		RPN(std::stack<u_lame>, std::string);

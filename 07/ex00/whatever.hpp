#pragma once

template	<typename T>
void	swap(T 	&a, T	&b) {
	T	temp = a;
	a = b;
	b = temp;
}

template	<typename B>
B		min(B a, B b)
{
	return (a < b ? a : b);
}

template	<typename C>
C		max(C a, C b)
{
	return (a > b ? a : b);
}

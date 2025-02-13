#pragma once
#include <iostream>

template		<typename A, typename B, typename C>
void		Iter(A	*arr, B	length,	C ( *fn )( A ))
{
	for (B i = 0; i < length; i++)
		fn( arr[i] );
}

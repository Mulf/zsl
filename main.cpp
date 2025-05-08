#include <iostream>
#include <zsl.h>


using namespace zsl;

int main()
{
	
	vector_d v = linspace(0, 10, 100);
	auto y = sin(v);

	return 0;
}